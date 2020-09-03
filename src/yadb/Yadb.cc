//
// Created by Yichen Xu on 2020/9/2.
//
#include <include/yadb/Yadb.h>

#include <utility>

namespace yadb {

    QString read_file(const QString& path) {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return {};
        }
        return file.readAll();
    }

    void write_file(const QString& path, const QByteArray& data) {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly)) {
            return;
        }
        file.write(data);
    }

    Yadb::Yadb(QString path) : _data {} {
        _path = std::move(path);
        QString content = read_file(_path);
        if (content.isEmpty()) {
            _data["_default"]["_count"] = 0;
            _data["_default"]["_data"] = json::array();
        } else {
            _data = json::parse(content.toStdString());
        }
        if (!this->_data.contains("_default")) {
            _data["_default"]["_count"] = 0;
            _data["_default"]["_data"] = json::array();
        }
        _table_name = "_default";
    }

    QString Yadb::path() const {
        return _path;
    }

    Yadb::~Yadb() {
        sync();
    }

    void Yadb::sync() const {
        auto data = QString::fromStdString(_data.dump());
        write_file(_path, data.toUtf8());
    }

    void Yadb::table(const QString& table_name) {
        _table_name = table_name;
        if (!_data.contains(_table_name.toStdString())) {
            _data[_table_name.toStdString()]["_count"] = 0;
            _data[_table_name.toStdString()]["_data"] = json::array();
        }
    }

    void Yadb::insert(json record) {
        int count = _data[_table_name.toStdString()]["_count"].get<int>();
        record["_id"] = count;
        _data[_table_name.toStdString()]["_data"].push_back(std::move(record));
        count += 1;
        _data[_table_name.toStdString()]["_count"] = count;
        sync();
    }

    QVector<json> Yadb::all() {
        return set().all();
    }

    Subset Yadb::set() {
        QVector<int> indices;
        int len = _data[_table_name.toStdString()]["_data"].size();
        for (int i = 0; i != len; i++) {
            indices.push_back(i);
        }
        return Subset(&_data, _table_name, indices);
    }

    json Yadb::get() {
        return set().get();
    }

    Subset Yadb::where(const shared_ptr<Predicate> &pred) {
        return set().where(pred);
    }

    void Yadb::update(const json &j) {
        return set().update(j);
    }

}

