//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/Inferno.h"
#include <action/BufAction.h>
#include <buff/buffs/HexBuff.h>
#include <buff/buffs/TypeActionBuff.h>

Inferno::Inferno()
        : SpAttackMove(120, MoveCat::MCFire) {}

string Inferno::name() const {
    return "炼狱之火";
}

Actions Inferno::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto att_act = SpAttackMove::move(self, target)[0];
    auto debuf_act = make_shared<BufAction>(
            make_shared<HexBuff>(SpDefense, -10, 3, "灼烧"),
            ActTarget
    );
    auto fire_buf = make_shared<TypeActionBuff>(
            MoveCat::MCFire,
            0.2,
            3,
            "炼狱"
    );
    auto buf_act = make_shared<BufAction>(fire_buf, ActSelf);

    return {att_act, debuf_act, buf_act};
}
