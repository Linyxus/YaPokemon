//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/FireThrower.h"
#include <buff/buffs/HexBuff.h>
#include <action/BufAction.h>

FireThrower::FireThrower()
        : SpAttackMove(100, MoveCat::MCFire) {

}

string FireThrower::name() const {
    return "火焰喷射";
}

Actions FireThrower::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    return {
            SpAttackMove::attack_action(self)[0],
            make_shared<BufAction>(
                    make_shared<HexBuff>(SpDefense, -10, 5, "灼伤"),
                    ActTarget
            )
    };
}
