//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/DragonClaw.h"

DragonClaw::DragonClaw()
        : AttackMove(100, MoveCat::MCDragon) {}

string DragonClaw::name() const {
    return "龙之爪";
}
