//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/DrillPeck.h"

DrillPeck::DrillPeck()
        : AttackMove(110, MoveCat::MCStorm) {}

string DrillPeck::name() const {
    return "猛啄";
}
