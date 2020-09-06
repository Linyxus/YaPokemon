//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/Pluck.h"
#include <action/HealAction.h>

Pluck::Pluck()
    : AttackMove(90, MoveCat::MCStorm)
{

}

string Pluck::name() const {
    return "啄食";
}

Actions Pluck::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto att_act = AttackMove::move(self, target)[0];
    auto att = dynamic_pointer_cast<AttackAction>(att_act);
    auto heal_act = make_shared<HealAction>(att->value / 5, ActSelf);

    return { att_act, heal_act };
}
