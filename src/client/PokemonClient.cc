//
// Created by Yichen Xu on 2020/9/3.
//

#include <include/client/PokemonClient.h>
#include <QNetworkDatagram>
#include <QVector>
#include <QString>
#include <utility>
#include <pokemon/pokemons/eevee.h>
#include <pokemon/pokemons/pikachu.h>
#include <pokemon/pokemons/type_map.h>

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
        ret = make_shared<PokemonOf<pokemon_of<PokemonEevee>::type>>();
    }
    if (pid == PokemonPikachu) {
        ret = make_shared<PokemonOf<pokemon_of<PokemonPikachu>::type>>();
    }
    if (pid == PokemonZacian) {
        ret = make_shared<PokemonOf<pokemon_of<PokemonZacian>::type>>();
    }
    if (pid == PokemonDragapult) {
        ret = make_shared<PokemonOf<pokemon_of<PokemonDragapult>::type>>();
    }
    if (pid == PokemonZamazenta) {
        ret = make_shared<PokemonOf<pokemon_of<PokemonZamazenta>::type>>();
    }
    if (pid == PokemonArcanine) {
        ret = make_shared<PokemonOf<pokemon_of<PokemonArcanine>::type>>();
    }
    if (pid == PokemonSnorlax) {
        ret = make_shared<PokemonOf<pokemon_of<PokemonSnorlax>::type>>();
    }
    if (pid == PokemonDuraludon) {
        ret = make_shared<PokemonOf<pokemon_of<PokemonDuraludon>::type>>();
    }
    if (pid == PokemonHaxorus) {
        ret = make_shared<PokemonOf<pokemon_of<PokemonHaxorus>::type>>();
    }
    if (pid == PokemonCorviknight) {
        ret = make_shared<PokemonOf<pokemon_of<PokemonCorviknight>::type>>();
    }
    if (pid == PokemonCharizard) {
        ret = make_shared<PokemonOf<pokemon_of<PokemonCharizard>::type>>();
    }
    if (pid == PokemonVileplume) {
        ret = make_shared<PokemonOf<pokemon_of<PokemonVileplume>::type>>();
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
    int inactive_duration = obj["inactive_duration"].get<int>();
    QVector<shared_ptr<Pokemon>> pokemons{};
    auto pokemon_indices = obj["pokemons"].get<vector<int>>();
    for (auto i : pokemon_indices) {
        pokemons.push_back(all_pokemons[i]);
    }

    return {username, pokemons, inactive_duration};
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

QString PokemonClient::signup(const QString &username, const QString &password) {
    auto u = username.toStdString();
    auto p = password.toStdString();
    json msg = compose_msg("user::register", {{"username", u},
                                              {"password", p}});
    json resp = request(msg);
    auto status = resp["status"].get<string>();
    if (status == "okay") {
        return {};
    } else {
        return QString::fromStdString(resp["error_msg"].get<string>());
    }
}

const QString &PokemonClient::username() const {
    return _username;
}

QVector<QString> PokemonClient::get_boss() {
    assert(!_token.isEmpty());
    json msg = compose_msg("battle::list_boss", {{"token", _token.toStdString()}});
    json resp = request(msg);
    auto status = resp["status"].get<string>();
    if (status == "okay") {
        // get users
        json boss = resp["boss"];
        auto vec = boss.get<vector<string>>();
        QVector<QString> ret{};
        for (const auto &s : vec) {
            ret.push_back(QString::fromStdString(s));
        }

        return ret;
    } else {
        return {};
    }
}

BattleResult PokemonClient::battle_exe(int pid, int boss_id) {
    assert(!_token.isEmpty());
    json msg = compose_msg("battle::exe",
                           {
                                   {"token",   _token.toStdString()},
                                   {"pid",     pid},
                                   {"boss_id", boss_id}
                           });
    json resp = request(msg);
    auto status = resp["status"].get<string>();
    if (status == "okay") {
        // parse the result
        return parse_result(resp["result"]);
    } else {
        return {};
    }
}

BattleResult PokemonClient::parse_result(const json &result) {
    QString winner = QString::fromStdString(result["winner"].get<string>());
    auto history = parse_history(result["history"]);

    return {winner, history};
}

BattleHistory PokemonClient::parse_history(const json &obj) {
    // type of `obj` should be array
    assert(obj.is_array());
    BattleState initial;
    initial.left = parse_pokemon_state(obj[0]["left"]);
    initial.right = parse_pokemon_state(obj[0]["right"]);

    BattleHistory ret;
    ret.initial = initial;
    for (int i = 1; i < obj.size(); i++) {
        ret.steps.push_back(parse_pokemon_step(obj[i]));
    }

    return ret;
}

PokemonState PokemonClient::parse_pokemon_state(const json &state) {
    QString name = QString::fromStdString(state["name"].get<string>());
    int level = state["level"].get<int>();
    int hp = state["hp"].get<int>();

    return {name, level, hp};
}

BattleStep PokemonClient::parse_pokemon_step(const json &step) {
    BattleStep ret;
    ret.current.left = parse_pokemon_state(step["left"]);
    ret.current.right = parse_pokemon_state(step["right"]);

    ret.turn = QString::fromStdString(step["round"]["turn"].get<string>());
    ret.miss = step["round"]["miss"].get<bool>();
    if (!ret.miss) {
        ret.move = QString::fromStdString(step["round"]["move"].get<string>());
    }

    return ret;
}

BattleResult PokemonClient::battle_real(int pid, int boss_id) {
    assert(!_token.isEmpty());
    json msg = compose_msg("battle::real",
                           {
                                   {"token",   _token.toStdString()},
                                   {"pid",     pid},
                                   {"boss_id", boss_id}
                           });
    json resp = request(msg);
    auto status = resp["status"].get<string>();
    if (status == "okay") {
        // parse the result
        return parse_result(resp["result"]);
    } else {
        return {};
    }
}

int PokemonClient::get_my_pokemon_id(int idx) {
    assert(!_token.isEmpty());
    json msg = compose_msg("pokemon::get_id",
                           {
                                   {"token",   _token.toStdString()},
                                   {"idx",     idx},
                           });
    json resp = request(msg);
    auto status = resp["status"].get<string>();
    if (status == "okay") {
        // parse the result
        return resp["pid"].get<int>();
    } else {
        return {};
    }
}

