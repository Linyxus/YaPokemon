//
// Created by Yichen Xu on 2020/9/3.
//

#ifndef YAPOKEMON_POKEMONSERVER_H
#define YAPOKEMON_POKEMONSERVER_H

#include <Yadb.h>
#include <QObject>
#include <QUdpSocket>
#include <include/server/Jwt.h>
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

    int create_pokemon(PokemonId pid);

    static QByteArray compose_error_resp(QString error_msg);
    static QByteArray compose_succ_resp(const json& succ_payload = json::object());

    json compose_user_json(const QString &username);
    json compose_user_list();
    json compose_pokemon_list();

    QByteArray user_register_handler(json payload);
    QByteArray user_auth_handler(json payload);
    QByteArray user_check_auth_handler(json payload);
    QByteArray user_list_handler(const json& payload);
    QByteArray pokemon_list_handler(const json& payload);
    void message_handler();
    yadb::Yadb _db;
    QUdpSocket _socket;
    const QByteArray jwt_secret = "19je9dhxplsa9";
};

#endif //YAPOKEMON_POKEMONSERVER_H
