//
// Created by Yichen Xu on 2020/9/1.
//

#include <buff/buffs/HexBuff.h>

HexBuff::HexBuff(AbilityAxis axis, llint value, llint expire, string name) {
    _axis = axis;
    _value = value;
    _name = name;
    _expire = expire;
}

void HexBuff::map_action(const shared_ptr<Action> &action) {
}

Hexagon<llint> HexBuff::map_current(const Hexagon<llint> &current) {
    auto ret = current;
    if (_axis == Hp) {
        ret.hp += _value;
        ret.hp = ret.hp < 0 ? 0 : ret.hp;
    }
    if (_axis == Attack) {
        ret.attack += _value;
        ret.attack = ret.attack < 0 ? 0 : ret.attack;
    }
    if (_axis == SpAttack) {
        ret.spAttack += _value;
        ret.spAttack = ret.spAttack < 0 ? 0 : ret.spAttack;
    }
    if (_axis == Defense) {
        ret.defense += _value;
        ret.defense = ret.defense < 0 ? 0 : ret.defense;
    }
    if (_axis == SpDefense) {
        ret.spDefense += _value;
        ret.spDefense = ret.spDefense < 0 ? 0 : ret.spDefense;
    }
    if (_axis == Speed) {
        ret.speed += _value;
        ret.speed = ret.speed < 0 ? 0 : ret.speed;
    }
    return ret;
}

string HexBuff::name() const {
    if (_name.size()) { return _name; }
    auto f = [](int v) -> string { if (v >= 0) return "增强"; else return "削弱"; };
    if (_axis == Attack) {
        return "攻击" + f(_value);
    }
    if (_axis == SpAttack) {
        return "特殊攻击" + f(_value);
    }
    if (_axis == Defense) {
        return "防御" + f(_value);
    }
    if (_axis == SpDefense) {
        return "特殊防御" + f(_value);
    }
    if (_axis == Speed) {
        return "速度" + f(_value);
    }
    return {};
}

bool HexBuff::expire() const {
    return _expire == 0;
}

void HexBuff::tick() {
    _expire -= 1;
}
