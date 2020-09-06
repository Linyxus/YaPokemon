//
// Created by Yichen Xu on 2020/9/5.
//

#include "include/core/move/moves/QuickGuard.h"
#include <buff/buffs/HexBuff.h>

QuickGuard::QuickGuard()
        : BufMove(static_pointer_cast<Buff>(make_shared<HexBuff>(Defense, 20, 3)), ActSelf) {
}

string QuickGuard::name() const {
    return "快速防守";
}
