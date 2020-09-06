//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/SheerCold.h"
#include <action/HealAction.h>

string SheerCold::name() const {
    return "绝对零度";
}

Actions SheerCold::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto miss = sample_miss(0.7);
    if (!miss) {
        return {
            make_shared<HealAction>(-2 * target->current().hp, ActTarget)
        };
    }
    return {};
}
