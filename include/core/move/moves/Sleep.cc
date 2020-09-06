//
// Created by Yichen Xu on 2020/9/6.
//

#include "Sleep.h"
#include <action/HealAction.h>

Actions Sleep::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    return {
        make_shared<HealAction>(self->pokemon()->max().hp / 5, ActSelf)
    };
}

string Sleep::name() const {
    return "睡觉";
}
