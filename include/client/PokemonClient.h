//
// Created by Yichen Xu on 2020/9/3.
//

#ifndef YAPOKEMON_POKEMONCLIENT_H
#define YAPOKEMON_POKEMONCLIENT_H

#include <QUdpSocket>
#include <QObject>
#include <pokemon/PokemonInstance.h>
#include <nlohmann/json.hpp>
using nlohmann::json;

struct PokemonUser {
    QString username;
    QVector<shared_ptr<Pokemon>> pokemons;
    int inactive_duration;
};

class PokemonClient : public QObject {
    Q_OBJECT
public:
    PokemonClient(QObject *parent, QHostAddress address, quint16 port);
    QString auth(const QString &username, const QString &password);
    QString signup(const QString &username, const QString &password);
    QVector<shared_ptr<Pokemon>> get_pokemons();
    QVector<PokemonUser> get_users();

    const QString &username() const;

private:
    json request(const json& msg);

    QString _token;
    QUdpSocket _socket;
    QString _username;
    QHostAddress _address;
    quint16 _port;
};

#endif //YAPOKEMON_POKEMONCLIENT_H
