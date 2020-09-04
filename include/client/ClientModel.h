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

class UserModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString username MEMBER m_username NOTIFY usernameChanged)
    Q_PROPERTY(int pokemonCount MEMBER m_pokemon_count NOTIFY pokemonCountChanged)
public:
    QString m_username;
    int m_pokemon_count;
Q_SIGNALS:
    void usernameChanged();
    void pokemonCountChanged();
};

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

class ClientModel : public QObject {
Q_OBJECT
    Q_PROPERTY(QVariant users READ getUsers NOTIFY usersChanged)
    Q_PROPERTY(QList<QObject *> userPokemons READ getUserPokemons NOTIFY usersChanged)
    Q_PROPERTY(int viewUser READ viewUser NOTIFY viewUserChanged)
public:
    ClientModel(QHostAddress addr, quint16 port, QObject *parent = 0);

    ~ClientModel() override = default;

    Q_INVOKABLE void pushPage(const QString &page);

    Q_INVOKABLE void popPage();

    QVariant getUsers();

    QList<QObject *> getUserPokemons();


    Q_INVOKABLE void updateUsers();

    Q_INVOKABLE QString auth(QString username, QString password);

    Q_INVOKABLE QString signup(QString username, QString password);

    int viewUser();

    Q_INVOKABLE void setViewUser(int i);

    Q_INVOKABLE int getAuthedUser();


Q_SIGNALS:

    void pagePushed(QString page);

    void pagePoped();

    void usersChanged();

    void viewUserChanged();

private:
    void fetch_users();

    PokemonClient _client;
    QVector<PokemonUser> _users;
    bool _users_valid;
    int _current_view_user;
};


#endif //YAPOKEMON_CLIENTMODEL_H
