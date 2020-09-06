//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/FlameWheel.h"

FlameWheel::FlameWheel()
        : AttackMove(120, MoveCat::MCFire) {
}

string FlameWheel::name() const {
    return "闪焰冲锋";
}

Actions FlameWheel::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto act = AttackMove::attack_action(self)[0];
    auto att = dynamic_pointer_cast<AttackAction>(act);
    auto att_self = make_shared<AttackAction>(*att);
    att_self->_target = ActSelf;
    att_self->value = 0.3 * double(att_self->value);
    return { att, att_self };
}
