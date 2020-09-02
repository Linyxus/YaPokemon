//
// Created by Yichen Xu on 2020/9/2.
//

#include <buff/buffs/TypeActionBuff.h>
#include <action/AttackAction.h>
#include <action/SpAttackAction.h>

TypeActionBuff::TypeActionBuff(MoveCat cat, double rate, uint expire, string name) {
    _cat = cat;
    _rate = rate;
    _expire = expire;
    _name = name;
}

void TypeActionBuff::tick() {
    if (_expire)
        _expire -= 1;
}

bool TypeActionBuff::expire() const {
    return _expire == 0;
}

Hexagon<uint> TypeActionBuff::map_current(const Hexagon<uint> &current) {
    return current;
}

void TypeActionBuff::map_action(const shared_ptr<Action> &action) {
    if (action->type() == ActAttack) {
        auto att = dynamic_pointer_cast<AttackAction>(action);
        if (att->attack_type == _cat) {
            uint x = (uint) (_rate * att->value);
            att->value += x;
        }
    }
    if (action->type() == ActSpAttack) {
        auto att = dynamic_pointer_cast<SpAttackAction>(action);
        if (att->attack_type == _cat) {
            uint x = (uint) (_rate * att->value);
            att->value += x;
        }
    }
}

string TypeActionBuff::name() const {
    return _name;
}

