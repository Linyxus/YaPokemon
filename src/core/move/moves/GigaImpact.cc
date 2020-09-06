//
// Created by Yichen Xu on 2020/9/5.
//

#include "include/core/move/moves/GigaImpact.h"

GigaImpact::GigaImpact() : AttackMove(120, MoveCat::MCSacred) {
}

string GigaImpact::name() const {
    return "巨兽斩";
}
