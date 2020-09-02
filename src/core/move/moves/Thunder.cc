//
// Created by Yichen Xu on 2020/9/1.
//

#include <move/moves/Thunder.h>

Thunder::Thunder() : SpAttackMove(110, MCThunder) {}

string Thunder::name() const {
    return "打雷";
}

