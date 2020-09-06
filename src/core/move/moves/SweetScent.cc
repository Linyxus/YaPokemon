//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/SweetScent.h"
#include <buff/buffs/HexBuff.h>
#include <action/HealAction.h>

SweetScent::SweetScent()
        : BufMove(
        make_shared<HexBuff>(SpDefense, -10, 3, "沉醉"),
        ActTarget) {}

string SweetScent::name() const {
    return "香甜气息";
}

Actions SweetScent::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto act = BufMove::move(self, target)[0];
    auto heal_self = make_shared<HealAction>(self->pokemon()->max().hp / 5);
    auto heal_target = make_shared<HealAction>(self->pokemon()->max().hp / 10, ActTarget);
    return { act, heal_self, heal_target };
}
