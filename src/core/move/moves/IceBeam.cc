//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/IceBeam.h"
#include <buff/buffs/HexBuff.h>
#include <action/BufAction.h>

IceBeam::IceBeam()
        : SpAttackMove(110, MoveCat::MCIce) {}

string IceBeam::name() const {
    return "冷冻光线";
}

Actions IceBeam::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto damage_act = SpAttackMove::move(self, target)[0];
    auto debuf_act = make_shared<BufAction>(
            make_shared<HexBuff>(Speed, -20, 2, "冰冻"),
            ActTarget
    );

    return { damage_act, debuf_act };
}
