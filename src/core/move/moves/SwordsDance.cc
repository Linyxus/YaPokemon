//
// Created by Yichen Xu on 2020/9/5.
//

#include "include/core/move/moves/SwordsDance.h"
#include <buff/buffs/HexBuff.h>

SwordsDance::SwordsDance()
        : BufMove(static_pointer_cast<Buff>(make_shared<HexBuff>(Attack, 20, 3)), ActSelf) {
}

string SwordsDance::name() const {
    return "剑舞";
}
