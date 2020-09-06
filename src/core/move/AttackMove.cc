//
// Created by Yichen Xu on 2020/9/1.
//

#include <move/AttackMove.h>
#include <action/AttackAction.h>

AttackMove::AttackMove(llint power, MoveCat cat) : power(power), cat(cat) {}

Actions AttackMove::attack_action(const shared_ptr<PokemonInstance>& self, ActionTarget t) {
    llint value = (int) (power2rate(power) * self->current().attack);
    auto ret = make_shared<AttackAction>(value, this->cat, t);
    return { ret };
}

Actions AttackMove::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    return attack_action(self);
}
