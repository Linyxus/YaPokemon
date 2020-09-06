//
// Created by Yichen Xu on 2020/9/3.
//

#include <include/server/PokemonServer.h>
#include <common.h>
#include <QMessageAuthenticationCode>
#include <utility>
#include <QNetworkDatagram>
#include <QDateTime>
#include <pokemon/pokemons/eevee.h>
#include <pokemon/pokemons/pikachu.h>
#include <pokemon/pokemons/type_map.h>
#include <move/Move.h>

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
        if (msg_type == "pokemon::get_id") {
            resp = pokemon_get_id(msg["payload"]);
        }
        if (msg_type == "battle::exe") {
            resp = battle_exe_handler(msg["payload"]);
        }
        if (msg_type == "battle::real") {
            resp = battle_real_handler(msg["payload"]);
        }
        if (msg_type == "battle::list_boss") {
            resp = battle_list_boss_handler(msg["payload"]);
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
    rec["exp"] = 50;
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
                {{"last_active", now},
                 {"username",    u}}
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
    for (const auto &username : usernames) {
        ret.push_back(compose_user_json(username));
    }

    return ret;
}

QByteArray PokemonServer::user_list_handler(const json &payload) {
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
    return _db.table("pokemons").raw_json()["pokemons"]["_data"];
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

BattleResult PokemonServer::run_battle(int pokemon_id, int boss_id, int boss_level) {
    assert(_db.table("pokemons").exists(_x_["_id"] == pokemon_id));
    auto pokemon = PokemonServer::pokemon_from_json(_db.table("pokemons").where(_x_["_id"] == pokemon_id).get());
    auto boss = PokemonServer::pokemon_from_info(_boss[boss_id], boss_level * 50);

    return BattleHistory::run_battle(pokemon, boss);
}

shared_ptr<Pokemon> PokemonServer::pokemon_from_json(json obj) {
    auto pid = static_cast<PokemonId>(obj["pokemon_id"].get<int>());
    int exp = obj["exp"].get<int>();
    return PokemonServer::pokemon_from_info(pid, exp);
}

shared_ptr<Pokemon> PokemonServer::pokemon_from_info(PokemonId pid, int exp) {
    if (pid == PokemonEevee) {
        auto ret = make_shared<PokemonOf<pokemon_of<PokemonEevee>::type>>();
        ret->learn(exp);
        return ret;
    }
    if (pid == PokemonPikachu) {
        auto ret = make_shared<PokemonOf<pokemon_of<PokemonPikachu>::type>>();
        ret->learn(exp);
        return ret;
    }
    if (pid == PokemonZacian) {
        auto ret = make_shared<PokemonOf<pokemon_of<PokemonZacian>::type>>();
        ret->learn(exp);
        return ret;
    }
    if (pid == PokemonDragapult) {
        auto ret = make_shared<PokemonOf<pokemon_of<PokemonDragapult>::type>>();
        ret->learn(exp);
        return ret;
    }
    if (pid == PokemonZamazenta) {
        auto ret = make_shared<PokemonOf<pokemon_of<PokemonZamazenta>::type>>();
        ret->learn(exp);
        return ret;
    }
    if (pid == PokemonArcanine) {
        auto ret = make_shared<PokemonOf<pokemon_of<PokemonArcanine>::type>>();
        ret->learn(exp);
        return ret;
    }
    if (pid == PokemonSnorlax) {
        auto ret = make_shared<PokemonOf<pokemon_of<PokemonSnorlax>::type>>();
        ret->learn(exp);
        return ret;
    }
    if (pid == PokemonDuraludon) {
        auto ret = make_shared<PokemonOf<pokemon_of<PokemonDuraludon>::type>>();
        ret->learn(exp);
        return ret;
    }
    if (pid == PokemonHaxorus) {
        auto ret = make_shared<PokemonOf<pokemon_of<PokemonHaxorus>::type>>();
        ret->learn(exp);
        return ret;
    }
    if (pid == PokemonCorviknight) {
        auto ret = make_shared<PokemonOf<pokemon_of<PokemonCorviknight>::type>>();
        ret->learn(exp);
        return ret;
    }
    if (pid == PokemonCharizard) {
        auto ret = make_shared<PokemonOf<pokemon_of<PokemonCharizard>::type>>();
        ret->learn(exp);
        return ret;
    }

    return nullptr;
}

BattleResult PokemonServer::exe_battle(int pokemon_id, int boss_id) {
    assert(_db.table("pokemons").exists(_x_["_id"] == pokemon_id));
    auto pokemon = PokemonServer::pokemon_from_json(_db.table("pokemons").where(_x_["_id"] == pokemon_id).get());
    auto boss_level = pokemon->level() + randint(0, 4);
    boss_level = boss_level > 15 ? 15 : boss_level;
    return run_battle(pokemon_id, boss_id, boss_level);
}

BattleResult PokemonServer::real_battle(int pokemon_id, int boss_id) {
    return run_battle(pokemon_id, boss_id, 15);
}

json PokemonServer::compose_pokemon_instance(const shared_ptr<PokemonInstance> &instance) {
    json ret;
    ret["name"] = instance->pokemon()->name();
    ret["level"] = instance->pokemon()->level();
    ret["hp"] = instance->current().hp;

    vector<string> buffs = {};
    for (const auto &b : instance->buff()) {
        buffs.push_back(b->name());
    }
    ret["buff"] = buffs;

    return ret;
}

json PokemonServer::compose_battle_round(const BattleRound &round) {
    json ret;
    ret["turn"] = round.turn == LeftTurn ? "left" : "right";
    ret["miss"] = round.miss;
    if (!round.miss && round.move) {
        ret["move"] = round.move->name();
    }

    return ret;
}

/**
 * 将对战结果序列化为JSON
 * @param result 对战结果
 * @return JSON
 *
 * JSON结构：
 *   { winner
 *     history [
 *       { miss move turn }
 *       left
 *       right
 *     ]
 *   }
 */
json PokemonServer::compose_battle_result(const BattleResult &result) {
    json ret;
    ret["winner"] = result.first == LeftWin ? "left" : "right";

    vector<json> history = {};
    for (const auto &step : result.second) {
        history.push_back(compose_battle_step(step));
    }
    ret["history"] = history;

    return ret;
}

json PokemonServer::compose_battle_step(const BattleStep &step) {
    json ret;
    ret["round"] = compose_battle_round(step.round);
    ret["left"] = compose_pokemon_instance(step.left);
    ret["right"] = compose_pokemon_instance(step.right);

    return ret;
}

bool PokemonServer::remove_user_pokemon(const QString &username, int id) {
    auto pokemons = _db.table("users")
            .where(_x_["username"] == username.toStdString())
            .get()["pokemons"]
            .get<std::vector<int>>();
    bool found = false;
    vector<int> p = {};
    for (auto i : pokemons) {
        if (i == id) {
            found = true;
        } else {
            p.push_back(i);
        }
    }

    if (!found) {
        return false;
    }

    _db.table("users")
            .where(_x_["username"] == username.toStdString())
            .update({{"pokemons", p}});

    return true;
}

/**
 * 处理练习赛请求
 * @param payload 请求载荷
 * @return
 */
QByteArray PokemonServer::battle_exe_handler(const json &payload) {
    auto username = check_req_auth(payload);
    if (username.isEmpty()) {
        return compose_error_resp("需要认证");
    }

    auto pid = payload["pid"].get<int>();
    auto boss_id = payload["boss_id"].get<int>();

    if (!verify_user_pokemon(username, pid)) {
        return compose_error_resp("用户无此精灵");
    }

    auto res = exe_battle(pid, boss_id);
    if (res.first == LeftWin) {
        int exp = Battle::get_exp(
                res.second[0].left->pokemon()->level(),
                res.second[0].right->pokemon()->level()
        );
        pokemon_learn(pid, exp);
    }
    _db.sync();

    auto result = compose_battle_result(res);
    return compose_succ_resp({{"result", result}});
}

/**
 * 处理挑战赛请求
 * @param payload
 * @return
 */
QByteArray PokemonServer::battle_real_handler(const json &payload) {
    auto username = check_req_auth(payload);
    if (username.isEmpty()) {
        return compose_error_resp("需要认证");
    }

    auto pid = payload["pid"].get<int>();
    auto boss_id = payload["boss_id"].get<int>();

    if (!verify_user_pokemon(username, pid)) {
        return compose_error_resp("用户无此精灵");
    }

    auto res = real_battle(pid, boss_id);
    if (res.first == LeftWin) {
        int exp = Battle::get_exp(
                res.second[0].left->pokemon()->level(),
                res.second[0].right->pokemon()->level()
        );
        pokemon_learn(pid, exp);
        auto id = create_pokemon(_boss[boss_id]);
        add_user_pokemon(username, id);
    } else {
        remove_user_pokemon(username, pid);

        auto pokemons = _db.table("users")
                .where(_x_["username"] == username.toStdString())
                .get()["pokemons"].get<vector<int>>();
        if (pokemons.empty()) {
            auto id = create_pokemon(rand_pokemon());
            add_user_pokemon(username, id);
        }
    }
    _db.sync();

    auto result = compose_battle_result(res);
    return compose_succ_resp({{"result", result}});
}

/**
 * 检查小精灵是否属于用户
 * @param username 用户名
 * @param pid 宝可梦编号
 * @return 是否属于用户
 */
bool PokemonServer::verify_user_pokemon(const QString &username, int pid) {
    auto pokemons = _db.table("users")
            .where(_x_["username"] == username.toStdString())
            .get()["pokemons"]
            .get<std::vector<int>>();
    for (auto i : pokemons) {
        if (i == pid) {
            return true;
        }
    }
    return false;
}

void PokemonServer::pokemon_learn(int pid, int exp) {
    auto q = _db.table("pokemons").where(_x_["_id"] == pid);
    assert(q.count() == 1);
    auto pokemon = q.get();
    auto old_exp = pokemon["exp"].get<int>();

    _db.where(_x_["_id"] == pid).update({{"exp", old_exp + exp}});
}

shared_ptr<Pokemon> PokemonServer::get_pokemon_by_id(int pid) {
    auto j = _db.table("pokemons")
            .where(_x_["_id"] == pid)
            .get();
    return pokemon_from_json(j);
}

void PokemonServer::add_user_pokemon(const QString &username, int pid) {
    auto u = username.toStdString();
    auto pokemons = _db.table("users")
            .where(_x_["username"] == u)
            .get()["pokemons"].get<vector<int>>();
    pokemons.push_back(pid);
    _db.where(_x_["username"] == u).update({{"pokemons", pokemons}});
}

json PokemonServer::compose_boss_list() {
    json ret = json::array();
    for (auto pid : _boss) {
        ret.push_back(pokemon_from_info(pid, 0)->name());
    }
    return ret;
}

QByteArray PokemonServer::battle_list_boss_handler(const json &payload) {
    auto username = check_req_auth(payload);
    if (username.isEmpty()) {
        return compose_error_resp("需要认证");
    }

    auto blist = compose_boss_list();
    return compose_succ_resp({{"boss", blist}});
}

QByteArray PokemonServer::pokemon_get_id(const json &payload) {
    auto username = check_req_auth(payload);
    if (username.isEmpty()) {
        return compose_error_resp("需要认证");
    }
    int idx = payload["idx"].get<int>();
    auto pokemons = _db.table("users")
            .where(_x_["username"] == username.toStdString())
            .get()["pokemons"].get<vector<int>>();
    return compose_succ_resp({{"pid", pokemons[idx]}});
}

