//
// Created by Yichen Xu on 2020/9/3.
//

#include <include/server/PokemonServer.h>
#include <common.h>
#include <QMessageAuthenticationCode>
#include <utility>
#include <QNetworkDatagram>
#include <QDateTime>

using yadb::_x_;

PokemonServer::PokemonServer(QObject *parent, quint16 port, QString db_path)
        : _db(std::move(db_path)), _socket(this),
          QObject(parent) {
    _socket.bind(QHostAddress::LocalHost, port);
    QObject::connect(&_socket, &QUdpSocket::readyRead, this, &PokemonServer::message_handler);
}

QString hash_password(const QString &password) {
    return QMessageAuthenticationCode::hash(password.toUtf8(), "", QCryptographicHash::Sha256).toHex();
}

QString gen_salt(int len) {
    const QString candidates("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    QString ret = {};
    while (len--) {
        ret.append(candidates[randint(0, candidates.length())]);
    }
    return ret;
}

int get_timestamp() {
    return QDateTime::currentMSecsSinceEpoch();
}

bool PokemonServer::user_register(const QString &username, const QString &password) {
    _db.table("users");
    string u = username.toStdString();
    if (_db.exists(_x_["username"] == u)) {
        return false;
    } else {
        QString salt = gen_salt(32);
        vector<int> pokemons = {};
        pokemons.reserve(3);
        for (int i = 0; i < 3; i++) {
            pokemons.push_back(create_pokemon(rand_pokemon()));
        }
        _db.table("users");
        _db.insert(
                {{"username", u},
                 {"passhash", hash_password(password + salt).toStdString()},
                 {"salt",     salt.toStdString()},
                 {"pokemons", pokemons}}
        );
        _db.sync();
        return true;
    }
}

QByteArray PokemonServer::compose_error_resp(QString error_msg) {
    json msg;
    msg["status"] = "error";
    msg["error_msg"] = error_msg.toStdString();
    return QByteArray::fromStdString(msg.dump());
}

QByteArray PokemonServer::user_register_handler(json payload) {
    QString username = QString::fromStdString(payload["username"].get<string>());
    QString password = QString::fromStdString(payload["password"].get<string>());
    if (password.isEmpty()) {
        return compose_error_resp("密码为空");
    }
    if (user_register(username, password)) {
        pulse(username);
        return compose_succ_resp();
    } else {
        return compose_error_resp("用户名重复");
    }
}

void PokemonServer::message_handler() {
    while (_socket.hasPendingDatagrams()) {
        QNetworkDatagram dgram = _socket.receiveDatagram();
        json msg = json::parse(dgram.data().constData());
        auto msg_type = msg["type"].get<string>();
        qDebug() << dgram.senderAddress() << ":" << dgram.senderPort() << " --> <" << msg_type.c_str() << ">";
        QByteArray resp;
        if (msg_type == "user::register") {
            resp = user_register_handler(msg["payload"]);
        }
        if (msg_type == "user::auth") {
            resp = user_auth_handler(msg["payload"]);
        }
        if (msg_type == "user::check_auth") {
            resp = user_check_auth_handler(msg["payload"]);
        }
        if (msg_type == "user::list") {
            resp = user_list_handler(msg["payload"]);
        }
        if (msg_type == "pokemon::list") {
            resp = pokemon_list_handler(msg["payload"]);
        }
        int status = _socket.writeDatagram(resp, dgram.senderAddress(), dgram.senderPort());
        if (status == -1) {
            qDebug() << "Fail to send response: udp error";
        }
    }
}

bool PokemonServer::verify_user(const QString &username, const QString &password) {
    _db.table("users");
    auto u = username.toStdString();
    if (!_db.exists(_x_["username"] == u)) {
        return false;
    }
    auto user_obj = _db.where(_x_["username"] == u).get();
    QString passhash = QString::fromStdString(user_obj["passhash"].get<string>());
    QString salt = QString::fromStdString(user_obj["salt"].get<string>());
    QString thishash = hash_password(password + salt);
    return passhash == thishash;
}

QByteArray PokemonServer::jwt_for_user(const QString &username) {
    _db.table("users");
    auto u = username.toStdString();
    auto q = _db.where(_x_["username"] == u);
    assert(q.count() == 1);
    int timestamp = get_timestamp();
    json jwt_payload;
    jwt_payload["username"] = u;
    jwt_payload["timestamp"] = timestamp;
    return encode_jwt(jwt_payload, jwt_secret);
}

QByteArray PokemonServer::user_auth_handler(json payload) {
    auto u = payload["username"].get<string>();
    auto p = payload["password"].get<string>();
    if (!verify_user(QString::fromStdString(u), QString::fromStdString(p))) {
        return compose_error_resp("用户登录信息错误");
    }
    pulse(QString::fromStdString(u));  // log user activity
    auto token = jwt_for_user(QString::fromStdString(u));
    auto s = token.toStdString();
    return compose_succ_resp(
            {{"token", s}}
    );
}

int PokemonServer::create_pokemon(PokemonId pid) {
    _db.table("pokemons");
    json rec;
    rec["pokemon_id"] = pid;
    rec["exp"] = 0;
    auto id = _db.insert(rec);
    _db.sync();
    return id;
}

QString PokemonServer::get_user(const QByteArray &token) {
    if (!verify_jwt(token, jwt_secret)) {
        return {};
    } else {
        json jwt = decode_jwt(token);
        return QString::fromStdString(jwt["username"].get<string>());
    }
}

QByteArray PokemonServer::compose_succ_resp(const json &succ_payload) {
    json msg;
    msg["status"] = "okay";
    msg.merge_patch(succ_payload);
    return QByteArray::fromStdString(msg.dump());
}

QByteArray PokemonServer::user_check_auth_handler(json payload) {
    auto token = payload["token"].get<string>();
    auto maybe_user = get_user(QByteArray::fromStdString(token));
    if (maybe_user.isEmpty()) {
        return compose_error_resp("验证失败");
    } else {
        return compose_succ_resp(
                {{"username", maybe_user.toStdString()}}
        );
    }
}

void PokemonServer::pulse(const QString &username) {
    int now = get_timestamp();
    auto u = username.toStdString();
    assert(_db.table("users").exists(_x_["username"] == u));
    if (!_db.table("pulse").exists(_x_["username"] == u)) {
        _db.insert(
                {{"last_active", now}, {"username", u}}
        );
    } else {
        _db.where(_x_["username"] == u).update(
                {{"last_active", now}}
        );
    }
    _db.sync();
}

int PokemonServer::inactive_duration(const QString &username) {
    auto u = username.toStdString();
    int now = get_timestamp();
    assert(_db.table("pulse").exists(_x_["username"] == u));
    auto last_active = _db.where(_x_["username"] == u).get()["last_active"].get<int>();

    return now - last_active;
}

json PokemonServer::compose_user_json(const QString &username) {
    auto u = username.toStdString();
    assert(_db.table("users").exists(_x_["username"] == u));
    json user = _db.where(_x_["username"] == u).get();
    json ret;
    ret["username"] = u;
    ret["pokemons"] = user["pokemons"];
    ret["inactive_duration"] = inactive_duration(username);

    return ret;
}

json PokemonServer::compose_user_list() {
    QVector<QString> usernames;
    for (auto user : _db.table("users").all()) {
        usernames.append(QString::fromStdString(user["username"].get<string>()));
    }
    json ret = json::array();
    for (const auto& username : usernames) {
        ret.push_back(compose_user_json(username));
    }

    return ret;
}

QByteArray PokemonServer::user_list_handler(const json& payload) {
    auto username = check_req_auth(payload);
    if (username.isEmpty()) {
        return compose_error_resp("需要认证");
    }
    auto ulist = compose_user_list();
    auto resp = compose_succ_resp({{"users", ulist}});
    return resp;
}

QString PokemonServer::check_req_auth(json payload) {
    if (!payload.contains("token")) return {};
    auto token = payload["token"].get<string>();

    auto u = get_user(QByteArray::fromStdString(token));
    if (!u.isEmpty()) {
        pulse(u);
    }
    return u;
}

json PokemonServer::compose_pokemon_list() {
    return _db.table("pokemons").raw_json()["pokemons"];
}

QByteArray PokemonServer::pokemon_list_handler(const json &payload) {
    auto username = check_req_auth(payload);
    if (username.isEmpty()) {
        return compose_error_resp("需要认证");
    }
    auto plist = compose_pokemon_list();
    auto resp = compose_succ_resp({{"pokemons", plist}});
    return resp;
}

