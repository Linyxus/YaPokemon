//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/buff/buffs/DeathBuff.h"

DeathBuff::DeathBuff(int limit) : _limit(limit + 1) {
}

void DeathBuff::map_action(const shared_ptr<Action> &action) {
    return;
}

Hexagon<llint> DeathBuff::map_current(const Hexagon<llint> &current) {
    auto ret = current;
    if (_limit <= 1) {
        ret.hp = 0;
    }
    return ret;
}

string DeathBuff::name() const {
    return "灭亡歌声";
}

bool DeathBuff::expire() const {
    return false;
}

void DeathBuff::tick() {
    _limit -= 1;
}
