//
// Created by Yichen Xu on 2020/9/1.
//

#include <buff/buffs/HexBuff.h>

HexBuff::HexBuff(AbilityAxis axis, uint value, uint expire, string name) {
    _axis = axis;
    _value = value;
    _name = name;
    _expire = expire;
}

void HexBuff::map_action(const shared_ptr<Action> &action) {
}

Hexagon<uint> HexBuff::map_current(const Hexagon<uint> &current) {
    auto ret = current;
    if (_axis == Hp) {
        ret.hp += _value;
    }
    if (_axis == Attack) {
        ret.attack += _value;
    }
    if (_axis == SpAttack) {
        ret.spAttack += _value;
    }
    if (_axis == Defense) {
        ret.defense += _value;
    }
    if (_axis == SpDefense) {
        ret.spDefense += _value;
    }
    if (_axis == Speed) {
        ret.speed += _value;
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
}

bool HexBuff::expire() const {
    return _expire == 0;
}

void HexBuff::tick() {
    _expire -= 1;
}
