//
// Created by Yichen Xu on 2020/9/1.
//

#include "move/SpAttackMove.h"

SpAttackMove::SpAttackMove(uint power, MoveCat cat) : power(power), cat(cat) {}

Actions SpAttackMove::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    return attack_action(self);
}

Actions SpAttackMove::attack_action(const shared_ptr<PokemonInstance> &self) {
    uint value = (int) (power2rate(power) * self->current().spAttack);
    auto ret = make_shared<SpAttackAction>(value, this->cat);
    return { ret };
}
