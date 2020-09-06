//
// Created by Yichen Xu on 2020/9/6.
//

#include "move/moves/DragonDance.h"
#include <buff/buffs/HexBuff.h>
#include <buff/buffs/TypeActionBuff.h>

DragonDance::DragonDance()
        : BufMove(static_pointer_cast<Buff>(make_shared<TypeActionBuff>(MoveCat::MCDragon, 0.3, 5, "龙之气场")), ActSelf) {
}

string DragonDance::name() const {
    return "龙之舞";
}

Actions DragonDance::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    auto self_act = BufMove::buf_action(ActSelf)[0];
    auto target_act = BufMove::buf_action(ActTarget)[0];

    return { self_act, target_act };
}
