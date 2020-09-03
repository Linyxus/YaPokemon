//
// Created by Yichen Xu on 2020/9/2.
//

#ifndef YAPOKEMON_SUBSET_H
#define YAPOKEMON_SUBSET_H

#include <nlohmann/json.hpp>
#include <QVector>
#include <memory>
using nlohmann::json;
using namespace std;

namespace yadb {

    enum OpType { OpEq, OpLe, OpLt, OpGe, OpGt, OpNeq };

    struct Selector {
        QVector<QString> fields;

        Selector operator[](const QString &field) const {
            auto ret = *this;
            ret.fields.push_back(field);
            return ret;
        }
    };

    class Predicate {
    public:
        virtual bool predicate(json obj) const = 0;
        Selector _selector;
    };

    template<typename T>
    class PredicateOf : public Predicate {
    public:
        PredicateOf(OpType op_type, Selector selector, const T &rval) {
            _op_type = op_type;
            _rval = rval;
            _selector = selector;
        }

        bool predicate(json obj) const override {
            auto x = obj.get<T>();
            if (_op_type == OpEq) {
                return x == _rval;
            }
            if (_op_type == OpNeq) {
                return x != _rval;
            }
            if (_op_type == OpGe) {
                return x >= _rval;
            }
            if (_op_type == OpGt) {
                return x > _rval;
            }
            if (_op_type == OpLe) {
                return x <= _rval;
            }
            if (_op_type == OpLt) {
                return x < _rval;
            }
            return true;
        }

        OpType _op_type;
        T _rval;

    };

    template<typename T>
    shared_ptr<Predicate> operator==(const Selector &selector, const T &val) {
        return make_shared<PredicateOf<T>>(OpEq, selector, val);
    }

    template<typename T>
    shared_ptr<Predicate> operator!=(const Selector &selector, const T &val) {
        return make_shared<PredicateOf<T>>(OpNeq, selector, val);
    }

    template<typename T>
    shared_ptr<Predicate> operator>(const Selector &selector, const T &val) {
        return make_shared<PredicateOf<T>>(OpGt, selector, val);
    }

    template<typename T>
    shared_ptr<Predicate> operator>=(const Selector &selector, const T &val) {
        return make_shared<PredicateOf<T>>(OpGe, selector, val);
    }

    template<typename T>
    shared_ptr<Predicate> operator<(const Selector &selector, const T &val) {
        return make_shared<PredicateOf<T>>(OpLt, selector, val);
    }

    template<typename T>
    shared_ptr<Predicate> operator<=(const Selector &selector, const T &val) {
        return make_shared<PredicateOf<T>>(OpLe, selector, val);
    }

    const Selector _x_({});

    class Subset {
    public:
        Subset(json *object, QString table_name, const QVector<int>& indices);
        QVector<json> all() const;
        json get() const;
        Subset where(const shared_ptr<Predicate> &pred);
        static json field_of(const json &obj, QVector<QString> f);
        void update(const json& obj);
        int count() const;
        bool exists(const shared_ptr<Predicate> &pred);

    private:
        QString _table_name;
        QVector<int> _indices;
        json *_object;
    };

}

#endif //YAPOKEMON_SUBSET_H
