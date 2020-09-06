//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/BellyDrum.h"
#include <buff/buffs/HexBuff.h>
#include <action/HealAction.h>

BellyDrum::BellyDrum()
        : BufMove(
        static_pointer_cast<Buff>(
                make_shared<HexBuff>(Attack, 100, 5, "斗志激增")
        ),
        ActSelf
) {}

string BellyDrum::name() const {
    return "腹鼓";
}

Actions BellyDrum::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto buf_act = BufMove::move(self, target)[0];
    auto hp = self->current().hp;
    auto heal_act = make_shared<HealAction>(-hp / 2);

    return { buf_act, heal_act };
}
