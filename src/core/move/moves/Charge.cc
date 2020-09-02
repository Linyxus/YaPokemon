//
// Created by Yichen Xu on 2020/9/2.
//

#include "move/moves/Charge.h"
#include <buff/buffs/HexBuff.h>

Charge::Charge()
        : BufMove(static_pointer_cast<Buff>(make_shared<HexBuff>(SpAttack, 11, 5)), ActSelf) {}

string Charge::name() const {
    return "充电";
}
