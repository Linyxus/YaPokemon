//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/SacredBlade.h"

SacredBlade::SacredBlade()
        : SpAttackMove(100, MoveCat::MCSacred) {}

string SacredBlade::name() const {
    return "圣剑";
}
