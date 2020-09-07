//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_BRINE_H
#define YAPOKEMON_BRINE_H

#include <move/SpAttackMove.h>

class Brine : public SpAttackMove {
public:
    Brine();
    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;

    string desc() const override {
        return "向对手喷射盐水。当对手生命值不足一半时伤害加倍。";
    }
};


#endif //YAPOKEMON_BRINE_H
