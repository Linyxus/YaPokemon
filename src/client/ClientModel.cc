//
// Created by Yichen Xu on 2020/9/3.
//

#include <include/client/ClientModel.h>
#include <battle/Battle.h>

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
        u->m_win_count = user.win_count;
        u->m_lose_count = user.lose_count;

        ret << u;
    }

    return QVariant::fromValue(ret);
}

ClientModel::ClientModel(QHostAddress addr, quint16 port, QObject *parent)
: QObject(parent), _client(this, addr, port) {
    _users_valid = false;
    _boss_list_valid = false;
    _current_view_user = 0;
    m_view_pokemon = 0;
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

QList<QObject *> ClientModel::getMyPokemons() {
    auto username = _client.username();
    if (!_users_valid) fetch_users();
    for (auto user : _users) {
        if (user.username != username) continue;
        QList<QObject *> ret;

        for (const auto& pokemon : user.pokemons) {
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

    return {};
}

void ClientModel::fetch_boss_list() {
    _boss_list = _client.get_boss();
}

QStringList ClientModel::getBossList() {
    if (!_boss_list_valid) fetch_boss_list();
    qDebug() << _boss_list;

    return QStringList(QList<QString>(_boss_list.cbegin(), _boss_list.cend()));
}

void ClientModel::updateBossList() {
    fetch_boss_list();
    emit bossListChanged();
}

void ClientModel::setBattlePokemon(int idx) {
    int pid = _client.get_my_pokemon_id(idx);
    _battle_pokemon = pid;
}

QObject *ClientModel::getBattleResult() {
    auto result = new ResultModel;

    result->m_winner = _battle_result.winner;

    result->m_steps = {};
    auto &steps = _battle_result.history.steps;
    for (int i = 0; i < _battle_result.history.steps.length(); i++) {
        auto step = new StepModel;
        auto left = new PokemonStateModel;
        auto right = new PokemonStateModel;
        left->m_name = steps[i].current.left.name;
        left->m_level = steps[i].current.left.level;
        left->m_hp = steps[i].current.left.hp;
        right->m_name = steps[i].current.right.name;
        right->m_level = steps[i].current.right.level;
        right->m_hp = steps[i].current.right.hp;

        step->m_current_left = left;
        step->m_current_right = right;
        step->m_turn = steps[i].turn;
        step->m_miss = steps[i].miss;
        step->m_move = steps[i].move;

        result->m_steps << step;
    }

    auto left = new PokemonStateModel;
    auto right = new PokemonStateModel;
    left->m_name = _battle_result.history.initial.left.name;
    left->m_level = _battle_result.history.initial.left.level;
    left->m_hp = _battle_result.history.initial.left.hp;
    right->m_name = _battle_result.history.initial.right.name;
    right->m_level = _battle_result.history.initial.right.level;
    right->m_hp = _battle_result.history.initial.right.hp;
    result->m_initial_left = left;
    result->m_initial_right = right;

    return result;
}

void ClientModel::startExeBattle(int boss_id) {
    _battle_result = _client.battle_exe(_battle_pokemon, boss_id);
    int exp = Battle::get_exp(_battle_result.history.initial.left.level, _battle_result.history.initial.right.level);
    if (_battle_result.winner == "left") {
        m_result_text = "恭喜你赢得了比赛！";
        m_result_text += "\n获得经验";
        m_result_text += QString::number(exp);
    } else {
        m_result_text = "你输了";
    }
    emit battleResultChanged();
    emit resultTextChanged();
}

void ClientModel::startRealBattle(int boss_id) {
    _battle_result = _client.battle_real(_battle_pokemon, boss_id);
    int exp = Battle::get_exp(_battle_result.history.initial.left.level, _battle_result.history.initial.right.level);
    if (_battle_result.winner == "left") {
        m_result_text = "你赢得了挑战赛\n获得了精灵" + _boss_list[boss_id];
        m_result_text += "\n获得经验";
        m_result_text += QString::number(exp);
    } else {
        m_result_text = "你输掉了挑战赛\n失去了精灵" + _battle_result.history.initial.left.name;
    }
    emit battleResultChanged();
    emit resultTextChanged();
}

int ClientModel::getViewSelf() {
    if (!_users_valid) return false;
    return _users[_current_view_user].username == _client.username();
}

int ClientModel::getUserNumBadge() {
    if (!_users_valid) return 0;
    auto pokemon_num = _users[_current_view_user].pokemons.length();
    if (pokemon_num < 5) return 0;
    if (pokemon_num < 10) return 1;
    if (pokemon_num < 15) return 2;
    return 3;
}

int ClientModel::getUserHLBadge() {
    if (!_users_valid) return 0;
    auto hl_num = 0;
    for (const auto& p : _users[_current_view_user].pokemons) {
        if (p->level() == 15) {
            hl_num++;
        }
    }
    if (hl_num < 5) return 0;
    if (hl_num < 10) return 1;
    if (hl_num < 15) return 2;
    return 3;
}

void ClientModel::setViewPokemon(int sel) {
    m_view_pokemon = sel;
    emit viewPokemonChanged();
}

QList<QObject *> ClientModel::getPokemonMoves() {
    QList<QObject *> ret;
    for (auto move : _users[_current_view_user].pokemons[m_view_pokemon]->temp()->moves()) {
        MoveModel *m = new MoveModel;
        m->m_name = QString::fromStdString(move->name());
        m->m_cat = QString::fromStdString(show_move_cat(move->move_cat()));
        m->m_desc = QString::fromStdString(move->desc());
        ret << m;
    }
    return ret;
}

