//
// Created by Yichen Xu on 2020/9/1.
//

#include <move/moves/Bite.h>

Bite::Bite() : AttackMove(80, MCNormal) {}

string Bite::name() const {
    return "咬";
}
