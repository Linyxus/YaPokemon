//
// Created by Yichen Xu on 2020/9/3.
//

#include <include/client/PokemonClient.h>
#include <QNetworkDatagram>
#include <utility>
#include <pokemon/pokemons/eevee.h>
#include <pokemon/pokemons/pikachu.h>

PokemonClient::PokemonClient(QObject *parent, QHostAddress address, quint16 port)
        : QObject(parent), _socket(this), _token{} {
    _address = std::move(address);
    _port = port;
}

json compose_msg(const QString &msg_type, json payload) {
    json ret;
    ret["type"] = msg_type.toStdString();
    ret["payload"] = std::move(payload);

    return ret;
}

QString PokemonClient::auth(const QString &username, const QString &password) {
    auto u = username.toStdString();
    auto p = password.toStdString();
    json msg = compose_msg("user::auth", {{"username", u},
                                          {"password", p}});
    json resp = request(msg);
    auto status = resp["status"].get<string>();
    if (status == "okay") {
        _token = QString::fromStdString(resp["token"].get<string>());
        _username = username;
        return {};
    } else {
        return QString::fromStdString(resp["error_msg"].get<string>());
    }
}

json PokemonClient::request(const json &msg) {
    QByteArray m = QByteArray::fromStdString(msg.dump());
    if (_socket.writeDatagram(m, _address, _port) == -1) {
        qDebug() << "Client request fail: udp write error";
        return json::object();
    }
    _socket.waitForReadyRead();
    QNetworkDatagram dgram = _socket.receiveDatagram();
    return json::parse(dgram.data());
}

shared_ptr<Pokemon> pokemon_from_json(json rec) {
    auto pid = static_cast<PokemonId>(rec["pokemon_id"].get<int>());
    int exp = rec["exp"].get<int>();

    shared_ptr<Pokemon> ret = nullptr;
    if (pid == PokemonEevee) {
        ret = make_shared<PokemonOf<Eevee>>();
    }
    if (pid == PokemonPikachu) {
        ret = make_shared<PokemonOf<Pikachu>>();
    }

    ret->learn(exp);
    return ret;
}

QVector<shared_ptr<Pokemon>> PokemonClient::get_pokemons() {
    assert(!_token.isEmpty());
    json msg = compose_msg("pokemon::list", {{"token", _token.toStdString()}});
    json resp = request(msg);
    auto status = resp["status"].get<string>();
    if (status == "okay") {
        // get pokemons
        json pokemons = resp["pokemons"];
        QVector<shared_ptr<Pokemon>> ret{};
        for (const auto &j : pokemons) {
            ret.append(pokemon_from_json(j));
        }

        return ret;
    } else {
        return {};
    }
}

PokemonUser user_from_json(json obj, const QVector<shared_ptr<Pokemon>> &all_pokemons) {
    QString username = QString::fromStdString(obj["username"].get<string>());
    QVector<shared_ptr<Pokemon>> pokemons{};
    auto pokemon_indices = obj["pokemons"].get<vector<int>>();
    for (auto i : pokemon_indices) {
        pokemons.push_back(all_pokemons[i]);
    }

    return {username, pokemons};
}

QVector<PokemonUser> PokemonClient::get_users() {
    assert(!_token.isEmpty());
    json msg = compose_msg("user::list", {{"token", _token.toStdString()}});
    json resp = request(msg);
    auto status = resp["status"].get<string>();
    if (status == "okay") {
        // get users
        json users = resp["users"];
        auto pokemons = get_pokemons();
        QVector<PokemonUser> ret{};
        for (auto obj : users) {
            ret.push_back(user_from_json(obj, pokemons));
        }

        return ret;
    } else {
        return {};
    }
}

