//
// Created by Yichen Xu on 2020/9/3.
//

#ifndef YAPOKEMON_JWT_H
#define YAPOKEMON_JWT_H

#include <QByteArray>
#include <nlohmann/json.hpp>
using nlohmann::json;

QByteArray encode_jwt(const json &payload, const QByteArray &secret);

bool verify_jwt(const QByteArray &jwt, const QByteArray &secret);

json decode_jwt(const QByteArray &jwt);

#endif //YAPOKEMON_JWT_H
