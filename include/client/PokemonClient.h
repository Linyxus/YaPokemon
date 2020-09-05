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

/**
 * Pokemon client class.
 */
class PokemonClient : public QObject {
Q_OBJECT
public:
    PokemonClient(QObject *parent, QHostAddress address, quint16 port);

    /**
     * Authenticate the client with given login info.
     * @param username
     * @param password
     * @return Error message. Return empty string if login succeeds.
     */
    QString auth(const QString &username, const QString &password);

    /**
     * Signup a new account.
     * @param username
     * @param password
     * @return Error message. Return empty if no error occurs.
     */
    QString signup(const QString &username, const QString &password);

    /**
     * Fetch pokemon list from the server.
     * @return Fetched pokemon list. Empty list if error occurs.
     *  Authentication is required.
     */
    QVector<shared_ptr<Pokemon>> get_pokemons();

    /**
     * Fetch user list from the server.
     * @return Fetched user list. Empty if error.
     *  Authentication is required.
     */
    QVector<PokemonUser> get_users();

    /**
     * Fetch boss name list from the server.
     * @return Fetched boss name list. Empty if error.
     *  Authentication required.
     */
    QVector<QString> get_boss();

    /**
     * Run a exercise battle between pokemon <pid> and boss <boss_id>.
     * @param pid Id of the selected pokemon.
     * @param boss_id Id of the selected boss.
     * @return Battle result of the exercise battle. Return empty if errors occurred.
     *  Note that the client must be authed and pokemon <pid> belongs to the authed user.
     */
    BattleResult battle_exe(int pid, int boss_id);

    /**
     * Start a real battle using pokemon <pid> with boss <boss_id>.
     * @param pid pokemon id
     * @param boss_id boss id
     * @return battle result
     */
    BattleResult battle_real(int pid, int boss_id);

    /**
     * Get the id of the idx-th pokemon of the currently logged-in user.
     * @param idx Pokemon index.
     * @return Fetched pokemon id.
     */
    int get_my_pokemon_id(int idx);

    /**
     * Parse battle result from json object.
     * @param result The json object to be parsed.
     * @return The parsed result.
     */
    static BattleResult parse_result(const json &result);

    /**
     * Parse battle history from given json object.
     * @param obj The json object to be parsed.
     * @return The parsed battle history. A json error will be thrown for invalid json object.
     */
    static BattleHistory parse_history(const json &history);

    /**
     * Parse pokemon state from json object.
     * @param state The json object to be parsed.
     * @return Parsed pokemon state. Will throw a json error if the json object is invalid.
     */
    static PokemonState parse_pokemon_state(const json &state);

    /**
     * Parse battle step from json.
     * @param step The json object to be parsed.
     * @return
     */
    static BattleStep parse_pokemon_step(const json &step);

    /**
     * Return authenticated username of the client.
     * @return The username.
     */
    const QString &username() const;

private:
    /**
     * Synchronously complete a udp request with given json encoded in body.
     * @param msg Message in json object.
     * @return The server response in json object.
     *  Will BLOCK if no response is received.
     */
    json request(const json &msg);

    QString _token;
    QUdpSocket _socket;
    QString _username;
    QHostAddress _address;
    quint16 _port;
};

#endif //YAPOKEMON_POKEMONCLIENT_H
