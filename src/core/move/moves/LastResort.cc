//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/LastResort.h"

LastResort::LastResort()
        : AttackMove(130, MoveCat::MCNormal) {
}

string LastResort::name() const {
    return "舍身冲撞";
}

Actions LastResort::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto act = AttackMove::attack_action(self)[0];
    auto att = dynamic_pointer_cast<AttackAction>(act);
    auto att_self = make_shared<AttackAction>(*att);
    att_self->_target = ActSelf;
    att_self->value = 0.5 * double(att_self->value);
    return { att, att_self };
}
