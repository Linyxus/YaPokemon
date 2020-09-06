//
// Created by Yichen Xu on 2020/9/6.
//

#include "move/moves/DragonDart.h"

DragonDart::DragonDart()
: AttackMove(100, MoveCat::MCDragon)
{

}

string DragonDart::name() const {
    return "龙箭";
}
