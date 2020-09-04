//
// Created by Yichen Xu on 2020/9/3.
//

#include <include/client/ClientModel.h>

void ClientModel::pushPage(const QString &page) {
    emit pagePushed(page);
}

void ClientModel::popPage() {
    emit pagePoped();
}

QVariant ClientModel::getUsers() {
    QList<QObject *> ret;
    if (!_users_valid) {
        fetch_users();
    }

    for (auto user : _users) {
        auto u = new UserModel;
        u->m_username = user.username;
        u->m_pokemon_count = user.pokemons.count();
        u->m_online = user.inactive_duration < 1000 * 60 * 5;

        ret << u;
    }

    return QVariant::fromValue(ret);
}

ClientModel::ClientModel(QHostAddress addr, quint16 port, QObject *parent)
: QObject(parent), _client(this, addr, port) {
    _users_valid = false;
    _current_view_user = 0;
}

void ClientModel::fetch_users() {
    _users_valid = true;
    _users = _client.get_users();
}

void ClientModel::updateUsers() {
    auto old = _users;
    fetch_users();
    emit usersChanged();
}

QString ClientModel::auth(QString username, QString password) {
    return _client.auth(username, password);
}

QString ClientModel::signup(QString username, QString password) {
    return _client.signup(username, password);
}

int ClientModel::viewUser() {
    return _current_view_user;
}

void ClientModel::setViewUser(int i) {
    if (_current_view_user != i) {
        _current_view_user = i;
        emit viewUserChanged();
    }
}

QList<QObject *> ClientModel::getUserPokemons() {
    QList<QObject *> ret;
    auto user = _users[_current_view_user];
    for (auto pokemon : user.pokemons) {
        auto poke = new PokemonModel;
        poke->m_level = pokemon->level();
        poke->m_name = QString::fromStdString(pokemon->name());
        poke->m_hp = pokemon->max().hp;
        poke->m_attack = pokemon->max().attack;
        poke->m_spAttack = pokemon->max().spAttack;
        poke->m_defense = pokemon->max().defense;
        poke->m_spDefense = pokemon->max().spDefense;
        poke->m_speed = pokemon->max().speed;

        ret << poke;
    }

    return ret;
}

int ClientModel::getAuthedUser() {
    if (!_users_valid) {
        fetch_users();
    }

    auto username = _client.username();
    for (int i = 0; i < _users.length(); i++) {
        if (username == _users[i].username) {
            return i;
        }
    }

    return 0;
}
