//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/RainDance.h"
#include <buff/buffs/TypeActionBuff.h>

Actions RainDance::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto buff = make_shared<TypeActionBuff>(MCWater, 0.2, 3, "下雨");
    auto debuff = make_shared<TypeActionBuff>(MCFire, -0.2, 3, "下雨");
    auto buff_act = make_shared<BufAction>(buff, ActSelf);
    auto debuff_act = make_shared<BufAction>(debuff, ActTarget);
    return {buff_act, debuff_act};
}

string RainDance::name() const {
    return "祈雨";
}
