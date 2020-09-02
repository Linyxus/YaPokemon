//
// Created by Yichen Xu on 2020/9/2.
//

#include <Yadb.h>
#include <QDebug>
#include <gtest/gtest.h>
using yadb::_x_;

TEST(YadbTest, OpenWorks) {
    yadb::Yadb db("db.json");
    db.table("users");

    db.insert({{"username", "linyxus"}, {"password", "123123"}});
    db.insert({{"username", "linyxus2"}, {"password", "1231232"}});

    db.table("pokemons");

    db.insert({{"name", "eevee"}, {"level", 2}});
    db.insert({{"name", "eevee"}, {"level", 15}});

    db.sync();

    db.set().where(_x_["level"] == 2).update({{"level", 3}});
}
