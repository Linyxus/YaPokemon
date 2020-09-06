//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/Outrage.h"
#include <buff/buffs/HexBuff.h>

Outrage::Outrage()
        : AttackMove(130, MoveCat::MCDragon) {}

string Outrage::name() const {
    return "逆鳞";
}

Actions Outrage::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto att_act = AttackMove::move(self, target)[0];
    auto debuf_act = make_shared<BufAction>(
            make_shared<HexBuff>(Defense, -20, 1, "狂躁"),
            ActSelf
    );

    return { att_act, debuf_act };
}
