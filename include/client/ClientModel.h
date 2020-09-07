//
// Created by Yichen Xu on 2020/9/3.
//

#ifndef YAPOKEMON_CLIENTMODEL_H
#define YAPOKEMON_CLIENTMODEL_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QUdpSocket>
#include <include/client/PokemonClient.h>

/**
 * Model for user.
 * Contains username, pokemon count and online state.
 */
class UserModel : public QObject {
Q_OBJECT
    Q_PROPERTY(QString username MEMBER m_username NOTIFY usernameChanged)
    Q_PROPERTY(int pokemonCount MEMBER m_pokemon_count NOTIFY pokemonCountChanged)
    Q_PROPERTY(bool online MEMBER m_online NOTIFY onlineChanged)
    Q_PROPERTY(int winCount MEMBER m_win_count)
    Q_PROPERTY(int loseCount MEMBER m_lose_count)
public:
    QString m_username;
    int m_pokemon_count;
    bool m_online;
    int m_win_count;
    int m_lose_count;
Q_SIGNALS:

    void usernameChanged();

    void pokemonCountChanged();

    void onlineChanged();
};

/**
 * Model for pokemon.
 * Contains pokemon name, level and hex
 */
class PokemonModel : public QObject {
Q_OBJECT
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int level MEMBER m_level)
    Q_PROPERTY(int hp MEMBER m_hp)
    Q_PROPERTY(int attack MEMBER m_attack)
    Q_PROPERTY(int spAttack MEMBER m_spAttack)
    Q_PROPERTY(int defense MEMBER m_defense)
    Q_PROPERTY(int spDefense MEMBER m_spDefense)
    Q_PROPERTY(int speed MEMBER m_speed)
public:
    QString m_name;
    int m_level;
    int m_hp;
    int m_attack;
    int m_spAttack;
    int m_defense;
    int m_spDefense;
    int m_speed;
};

/**
 * Model for pokemon state in the battle.
 * Contains pokemon name, level and current hp.
 */
class PokemonStateModel : public QObject {
Q_OBJECT
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int level MEMBER m_level)
    Q_PROPERTY(int hp MEMBER m_hp)
public:
    QString m_name;
    int m_level;
    int m_hp;
};

/**
 * Model for battle step.
 * Contains current pokemon state, turn, miss and move name (optional).
 */
class StepModel : public QObject {
Q_OBJECT
    Q_PROPERTY(QObject *currentLeft MEMBER m_current_left)
    Q_PROPERTY(QObject *currentRight MEMBER m_current_right)
    Q_PROPERTY(QString turn MEMBER m_turn)
    Q_PROPERTY(bool miss MEMBER m_miss)
    Q_PROPERTY(QString move MEMBER m_move)
public:
    QObject *m_current_left;
    QObject *m_current_right;
    QString m_turn;
    bool m_miss;
    QString m_move;
};

/**
 * Model for battle result.
 * Conatins the final winner, initial state and battle steps.
 */
class ResultModel : public QObject {
Q_OBJECT
    Q_PROPERTY(QObject *initialLeft MEMBER m_initial_left)
    Q_PROPERTY(QObject *initialRight MEMBER m_initial_right)
    Q_PROPERTY(QString winner MEMBER m_winner)
    Q_PROPERTY(QList<QObject *> steps MEMBER m_steps)
public:
    QObject *m_initial_left;
    QObject *m_initial_right;
    QString m_winner;
    QList<QObject *> m_steps;
};

class MoveModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(QString cat MEMBER m_cat)
    Q_PROPERTY(QString desc MEMBER m_desc)
public:
    QString m_name;
    QString m_cat;
    QString m_desc;
};

/**
 * Qml model for client-side logic.
 */
class ClientModel : public QObject {
Q_OBJECT
    Q_PROPERTY(QVariant users READ getUsers NOTIFY usersChanged)
    Q_PROPERTY(QList<QObject *> userPokemons READ getUserPokemons NOTIFY usersChanged)
    Q_PROPERTY(int viewUser READ viewUser NOTIFY viewUserChanged)
    Q_PROPERTY(int userNumBadge READ getUserNumBadge NOTIFY viewUserChanged)
    Q_PROPERTY(int userHLBadge READ getUserHLBadge NOTIFY viewUserChanged)
    Q_PROPERTY(bool viewSelf READ getViewSelf NOTIFY viewUserChanged)
    Q_PROPERTY(QList<QObject *> myPokemons READ getMyPokemons NOTIFY usersChanged)
    Q_PROPERTY(QStringList bossList READ getBossList NOTIFY bossListChanged)
    Q_PROPERTY(QObject* battleResult READ getBattleResult NOTIFY battleResultChanged)
    Q_PROPERTY(QString resultText MEMBER m_result_text NOTIFY resultTextChanged)
    Q_PROPERTY(int viewPokemon MEMBER m_view_pokemon NOTIFY viewPokemonChanged)
    Q_PROPERTY(QList<QObject *> pokemonMoves READ getPokemonMoves NOTIFY viewPokemonChanged)
public:
    ClientModel(QHostAddress addr, quint16 port, QObject *parent = 0);

    ~ClientModel() override = default;

    /**
     * Push a Qml page in stack.
     * @param page The url of the Qml page to be pushed.
     * The `pushPage`, `popPage` functions and related signals are used to instruct the
     * `StackView` to properly handle page navigations.
     * In other words, they are the `backend' of the stack view.
     */
    Q_INVOKABLE void pushPage(const QString &page);

    /**
     * Pop a qml page from the stack.
     */
    Q_INVOKABLE void popPage();

    /**
     * Fetch user list and return as Qml data model.
     * @return Qml data model of fetched user list.
     */
    QVariant getUsers();

    /**
     * Get user pokemon list of the selected user profile.
     * @return
     */
    QList<QObject *> getUserPokemons();

    /**
     * Get user pokemon of currently logged-in user.
     * @return
     */
    QList<QObject *> getMyPokemons();

    /**
     * Re-fetch user list from server.
     */
    Q_INVOKABLE void updateUsers();

    /**
     * Authenticate client with provided auth info.
     * @param username
     * @param password
     * @return
     */
    Q_INVOKABLE QString auth(QString username, QString password);

    /**
     * Sign up a new account.
     * @param username
     * @param password
     * @return
     */
    Q_INVOKABLE QString signup(QString username, QString password);

    /**
     * Get currently selected user profile.
     * @return
     */
    int viewUser();

    /**
     * Set currently viewing user profile.
     * @param i
     */
    Q_INVOKABLE void setViewUser(int i);

    /**
     * Check whether Qml model is set to view the authed user.
     * @return
     */
    int getViewSelf();

    /**
     * Get authenticated user.
     * @return
     */
    Q_INVOKABLE int getAuthedUser();

    /**
     * Re-fetch boss list from server.
     */
    Q_INVOKABLE void updateBossList();

    /**
     * Fetch boss name list and compose as Qml string list model.
     * @return
     */
    QStringList getBossList();

    /**
     * Select pokemon to battle.
     * @param idx
     */
    Q_INVOKABLE void setBattlePokemon(int idx);

    /**
     * Start a exercise battle with selected boss.
     * @param boss_id
     */
    Q_INVOKABLE void startExeBattle(int boss_id);

    /**
     * See `startExeBattle`; start a real battle.
     * @param boss_id
     */
    Q_INVOKABLE void startRealBattle(int boss_id);

    /**
     * Get stored battle result, composed as Qml data model.
     * @return
     */
    QObject *getBattleResult();

    /**
     * Get user pokemon number badge level.
     * @return
     */
    int getUserNumBadge();

    /**
     * Get user pokemon high-level badge level.
     * @return
     */
    int getUserHLBadge();

    /**
     * Result text to be shown when the battle finishes.
     */
    QString m_result_text;

    /**
     * The pokemon currently selected for viewing.
     */
    int m_view_pokemon;

    Q_INVOKABLE void setViewPokemon(int sel);

    QList<QObject *> getPokemonMoves();

Q_SIGNALS:

    void pagePushed(QString page);

    void pagePoped();

    void usersChanged();

    void viewUserChanged();

    void bossListChanged();

    void battleResultChanged();

    void resultTextChanged();

    void viewPokemonChanged();

private:
    void fetch_users();

    void fetch_boss_list();

    PokemonClient _client;
    QVector<PokemonUser> _users;
    QVector<QString> _boss_list;
    bool _users_valid;
    bool _boss_list_valid;
    int _current_view_user;
    int _battle_pokemon;
    BattleResult _battle_result;
};


#endif //YAPOKEMON_CLIENTMODEL_H
