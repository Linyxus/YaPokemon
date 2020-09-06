//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_DRAGONCLAW_H
#define YAPOKEMON_DRAGONCLAW_H

#include <move/AttackMove.h>

class DragonClaw : public AttackMove {
public:
    DragonClaw();
    ~DragonClaw() = default;

    string name() const override;
};


#endif //YAPOKEMON_DRAGONCLAW_H
