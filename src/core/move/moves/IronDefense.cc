//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/IronDefense.h"
#include <buff/buffs/HexBuff.h>
#include <action/BufAction.h>

string IronDefense::name() const {
    return "钢铁防御";
}

Actions IronDefense::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    return {
            make_shared<BufAction>(
                    make_shared<HexBuff>(Defense, 100, 2),
                    ActSelf
            ),
            make_shared<BufAction>(
            make_shared<HexBuff>(SpDefense, 100, 2),
            ActSelf
            )
    };
}
