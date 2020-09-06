//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/Brine.h"

string Brine::name() const {
    return "盐水";
}

Actions Brine::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto act = SpAttackMove::move(self, target)[0];
    auto att = dynamic_pointer_cast<SpAttackAction>(act);
    if (target->current().hp * 2 <= target->pokemon()->max().hp) {
        att->value *= 2;
    }

    return {att};
}

Brine::Brine()
        : SpAttackMove(90, MoveCat::MCWater) {}
