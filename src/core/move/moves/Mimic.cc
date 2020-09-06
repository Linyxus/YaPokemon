//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/Mimic.h"

Actions Mimic::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto i = weighted_sample(target->pokemon()->temp()->move_weights());
    auto move = target->pokemon()->temp()->moves()[i];
    return move->move(self, target);
}

string Mimic::name() const {
    return "模仿";
}
