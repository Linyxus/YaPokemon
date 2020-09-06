//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/GigaDrain.h"
#include <action/HealAction.h>

GigaDrain::GigaDrain()
        : SpAttackMove(90, MoveCat::MCGrass) {}

string GigaDrain::name() const {
    return "超级吸取";
}

Actions GigaDrain::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto att_act = SpAttackMove::move(self, target)[0];
    auto att = dynamic_pointer_cast<SpAttackAction>(att_act);
    auto val = att->value / 2;
    auto heal_act = make_shared<HealAction>(val, ActSelf);

    return { att, heal_act };
}

