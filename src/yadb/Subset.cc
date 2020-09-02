//
// Created by Yichen Xu on 2020/9/2.
//

#include <include/yadb/Subset.h>

#include <utility>

yadb::Subset::Subset(json *object, QString table_name, const QVector<int>& indices) {
    _object = object;
    _table_name = std::move(table_name);
    _indices = indices;
}

QVector<json> yadb::Subset::all() const {
    QVector<json> ret {};
    for (auto i : _indices) {
        ret.push_back((*_object)[_table_name.toStdString()]["_data"][i]);
    }
    return ret;
}



json yadb::Subset::field_of(const json &obj, QVector<QString> f) {
    auto ret = obj;
    for (const auto& s : f) {
        ret = ret[s.toStdString()];
    }
    return ret;
}

yadb::Subset yadb::Subset::where(const shared_ptr<Predicate> &pred) {
    json object = *_object;
    json records = object[_table_name.toStdString()]["_data"];
    QVector<int> indices = {};

    for (int i : _indices) {
        json rec = records[i];
        json val = field_of(rec, pred->_selector.fields);
        if (pred->predicate(val)) {
            indices.push_back(i);
        }
    }

    return { _object, _table_name, indices };
}

json yadb::Subset::get() const {
    return all()[0];
}

void yadb::Subset::update(const json& obj) {
    json &object = *_object;
    json &records = object[_table_name.toStdString()]["_data"];
    for (int i : _indices) {
        records[i].merge_patch(obj);
    }
}

