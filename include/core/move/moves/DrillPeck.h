//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_DRILLPECK_H
#define YAPOKEMON_DRILLPECK_H

#include <move/AttackMove.h>

class DrillPeck : public AttackMove {
public:
    DrillPeck();
    ~DrillPeck() = default;

    string name() const override;
};


#endif //YAPOKEMON_DRILLPECK_H
