//
// Created by Yichen Xu on 2020/8/28.
//

#ifndef POKEMON_CORE_POKEMONINSTANCE_H
#define POKEMON_CORE_POKEMONINSTANCE_H

#include <pokemon/Pokemon.h>
#include <buff/Buff.h>
#include <action/AttackAction.h>
#include <action/SpAttackAction.h>
#include <action/BufAction.h>
#include <action/HealAction.h>
#include <vector>
#include <memory>

using namespace std;

class PokemonInstance {
public:
    PokemonInstance() = default;

    ~PokemonInstance() = default;

    virtual const Pokemon *pokemon() const = 0;

    virtual Hexagon<llint> current() const = 0;

    virtual void accept_action(shared_ptr<Action> action) = 0;

    virtual void accept_actions(const Actions &actions) {
        for (const auto &act : actions) {
            accept_action(act);
        }
    }

    virtual vector<shared_ptr<Buff>> buff() const = 0;
    virtual void update_buff() = 0;

    virtual shared_ptr<PokemonInstance> clone() const = 0;
};

template<typename T>
class PokemonInstanceOf : public PokemonInstance {
public:
    explicit PokemonInstanceOf(const PokemonOf<T> &pokemon);

    ~PokemonInstanceOf() = default;

    const Pokemon *pokemon() const override;

    Hexagon<llint> current() const override;

    void accept_action(shared_ptr<Action> action) override;

    vector<shared_ptr<Buff>> buff() const override;

    void update_buff() override;

    shared_ptr<PokemonInstance> clone() const override;

private:
    PokemonOf<T> _pokemon;
    Hexagon<llint> _current;
    vector<shared_ptr<Buff>> _buff;
};

template<typename T>
PokemonInstanceOf<T>::PokemonInstanceOf(const PokemonOf<T> &pokemon)
        : _pokemon(pokemon), _current(pokemon.max()), _buff{} {
}

template<typename T>
const Pokemon *PokemonInstanceOf<T>::pokemon() const {
    return &_pokemon;
}

template<typename T>
Hexagon<llint> PokemonInstanceOf<T>::current() const {
    Hexagon<llint> ret = _current;
    for (const auto &p : _buff) {
        ret = p->map_current(_current);
    }

    return ret;
}

template<typename T>
void PokemonInstanceOf<T>::accept_action(shared_ptr<Action> action) {
    if (action->type() == ActAttack) {
        shared_ptr<AttackAction> p = dynamic_pointer_cast<AttackAction, Action>(action);
        double r = defense2rate(_current.defense);
        r = 1. - r;
        llint val = (int) (r * p->value);
        if (this->_current.hp >= val) {
            this->_current.hp -= val;
        } else {
            this->_current.hp = 0;
        }
    }
    if (action->type() == ActSpAttack) {
        shared_ptr<SpAttackAction> p = dynamic_pointer_cast<SpAttackAction, Action>(action);
        double r = defense2rate(_current.spDefense);
        r = 1. - r;
        llint val = (int) (r * p->value);
        if (this->_current.hp >= val) {
            this->_current.hp -= val;
        } else {
            this->_current.hp = 0;
        }
    }
    if (action->type() == ActBuf) {
        shared_ptr<BufAction> buff_act = dynamic_pointer_cast<BufAction>(action);
        this->_buff.push_back(buff_act->_buff);
    }
    if (action->type() == ActHeal) {
        shared_ptr<HealAction> heal_act = dynamic_pointer_cast<HealAction>(action);
        this->_current.hp += heal_act->value;
        if (this->_current.hp < 0) {
            this->_current.hp = 0;
        }
        if (this->_current.hp > this->pokemon()->max().hp) {
            this->_current.hp = this->pokemon()->max().hp;
        }
    }
}

template<typename T>
vector<shared_ptr<Buff>> PokemonInstanceOf<T>::buff() const {
    return _buff;
}

template<typename T>
void PokemonInstanceOf<T>::update_buff() {
    vector<shared_ptr<Buff>> new_buff {};
    for (const auto& b : _buff) {
        b->tick();
        if (!b->expire()) {
            new_buff.push_back(b);
        }
    }
    _buff = new_buff;
}

template<typename T>
shared_ptr<PokemonInstance> PokemonInstanceOf<T>::clone() const {
    shared_ptr<PokemonInstanceOf<T>> ret = make_shared<PokemonInstanceOf<T>>(*this);
    return ret;
}

template<typename T>
shared_ptr<PokemonInstanceOf<T>> get_instance_of(shared_ptr<PokemonOf<T>> pokemon);

shared_ptr<PokemonInstance> instance_of(const shared_ptr<Pokemon>& pokemon);

#endif //POKEMON_CORE_POKEMONINSTANCE_H
