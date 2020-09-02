//
// Created by Yichen Xu on 2020/9/2.
//

#ifndef YAPOKEMON_YADB_H
#define YAPOKEMON_YADB_H

#include <nlohmann/json.hpp>
#include <QString>
#include <QVector>
#include <QFile>
#include <Subset.h>
using nlohmann::json;

namespace yadb {

    class Yadb {
    public:
        explicit Yadb(QString path);
        ~Yadb();

        [[nodiscard]] QString path() const;
        void sync() const;

        void table(const QString& table_name);
        void insert(json record);

        Subset set();
        QVector<json> all();

        inline json raw_json() const { return _data; }
    private:
        QString _path;
        json _data;
        QString _table_name;
    };
}

#endif //YAPOKEMON_YADB_H
