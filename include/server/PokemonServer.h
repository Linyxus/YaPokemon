//
// Created by Yichen Xu on 2020/9/3.
//

#ifndef YAPOKEMON_POKEMONSERVER_H
#define YAPOKEMON_POKEMONSERVER_H

#include <Yadb.h>
#include <QObject>
#include <QUdpSocket>
#include <include/server/Jwt.h>
#include <include/server/BattleHistory.h>
#include <pokemon/def.h>
#include <pokemon/Pokemon.h>
#include <pokemon/PokemonInstance.h>

class PokemonServer : public QObject {
    Q_OBJECT
public:
    explicit PokemonServer(QObject *parent, quint16 port, QString db_path = "db.json");

private:
    bool user_register(const QString& username, const QString &password);
    bool verify_user(const QString &username, const QString &password);
    QByteArray jwt_for_user(const QString &username);
    QString get_user(const QByteArray &token);
    QString check_req_auth(json payload);
    void pulse(const QString &username);
    int inactive_duration(const QString &username);
    pair<int, int> win_lose_count(const QString &username);
    BattleResult run_battle(int pokemon_id, int boss_id, int boss_level);
    BattleResult exe_battle(int pokemon_id, int boss_id);
    BattleResult real_battle(int pokemon_id, int boss_id);
    bool remove_user_pokemon(const QString &username, int pokemon_id);
    void add_user_pokemon(const QString &username, int pid);
    bool verify_user_pokemon(const QString &username, int pid);
    void pokemon_learn(int pid, int exp);

    int create_pokemon(PokemonId pid);
    shared_ptr<Pokemon> get_pokemon_by_id(int pid);
    static shared_ptr<Pokemon> pokemon_from_info(PokemonId pid, int exp);
    static shared_ptr<Pokemon> pokemon_from_json(json obj);

    static QByteArray compose_error_resp(QString error_msg);
    static QByteArray compose_succ_resp(const json& succ_payload = json::object());

    json compose_user_json(const QString &username);
    json compose_user_list();
    json compose_pokemon_list();
    json compose_boss_list();
    static json compose_pokemon_instance(const shared_ptr<PokemonInstance> &instance);
    static json compose_battle_round(const BattleRound &round);
    static json compose_battle_step(const BattleStep &step);
    static json compose_battle_result(const BattleResult &result);

    QByteArray user_register_handler(json payload);
    QByteArray user_auth_handler(json payload);
    QByteArray user_check_auth_handler(json payload);
    QByteArray user_list_handler(const json& payload);
    QByteArray pokemon_list_handler(const json& payload);
    QByteArray pokemon_get_id(const json &payload);
    QByteArray battle_exe_handler(const json& payload);
    QByteArray battle_real_handler(const json& payload);
    QByteArray battle_list_boss_handler(const json& payload);
    void message_handler();

    yadb::Yadb _db;
    QUdpSocket _socket;
    const QByteArray jwt_secret = "19je9dhxplsa9";
    QVector<PokemonId> _boss = {
            PokemonZacian,
            PokemonZamazenta,
            PokemonLapras,
            PokemonDragapult,
            PokemonDuraludon,
            PokemonHaxorus,
            PokemonArcanine,
            PokemonCharizard,
            PokemonCorviknight,
            PokemonEevee,
            PokemonDitto,
            PokemonVileplume,
            PokemonSnorlax,
            PokemonPikachu,
    };
};

#endif //YAPOKEMON_POKEMONSERVER_H
