//
// Created by Yichen Xu on 2020/9/3.
//

#ifndef YAPOKEMON_POKEMONCLIENT_H
#define YAPOKEMON_POKEMONCLIENT_H

#include <QUdpSocket>
#include <QObject>
#include <move/Move.h>
#include <battle/Battle.h>
#include <pokemon/PokemonInstance.h>
#include <nlohmann/json.hpp>

using nlohmann::json;

struct PokemonUser {
    QString username;
    QVector<shared_ptr<Pokemon>> pokemons;
    int inactive_duration;
};

struct PokemonState {
    QString name;
    int level;
    int hp;
};

struct BattleState {
    PokemonState left;
    PokemonState right;
};

struct BattleStep {
    QString move;
    QString turn;
    bool miss;
    BattleState current;
};

struct BattleHistory {
    BattleState initial;
    QVector<BattleStep> steps;
};

struct BattleResult {
    QString winner;
    BattleHistory history;
};

class PokemonClient : public QObject {
Q_OBJECT
public:
    PokemonClient(QObject *parent, QHostAddress address, quint16 port);

    QString auth(const QString &username, const QString &password);

    QString signup(const QString &username, const QString &password);

    QVector<shared_ptr<Pokemon>> get_pokemons();

    QVector<PokemonUser> get_users();

    QVector<QString> get_boss();

    BattleResult battle_exe(int pid, int boss_id);

    BattleResult battle_real(int pid, int boss_id);

    static BattleResult parse_result(const json &result);

    static BattleHistory parse_history(const json &history);

    static PokemonState parse_pokemon_state(const json &state);

    static BattleStep parse_pokemon_step(const json &step);

    const QString &username() const;

private:
    json request(const json &msg);

    QString _token;
    QUdpSocket _socket;
    QString _username;
    QHostAddress _address;
    quint16 _port;
};

#endif //YAPOKEMON_POKEMONCLIENT_H
