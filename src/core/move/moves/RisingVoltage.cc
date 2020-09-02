//
// Created by Yichen Xu on 2020/9/2.
//

#include "move/moves/RisingVoltage.h"
#include <buff/buffs/TypeActionBuff.h>

RisingVoltage::RisingVoltage()
        : BufMove(static_pointer_cast<Buff>(make_shared<TypeActionBuff>(MCThunder, 0.5, 2, "高电压")), ActSelf) {
}

string RisingVoltage::name() const {
    return "电压过载";
}
