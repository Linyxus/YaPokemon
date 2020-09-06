//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/BodySlam.h"

BodySlam::BodySlam()
        : AttackMove(100, MCNormal) {}

string BodySlam::name() const {
    return "泰山压顶";
}

Actions BodySlam::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto att = dynamic_pointer_cast<AttackAction>(AttackMove::move(self, target)[0]);
    att->value += self->current().hp / 2;

    return { att };
}
