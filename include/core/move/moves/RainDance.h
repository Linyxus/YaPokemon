//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_RAINDANCE_H
#define YAPOKEMON_RAINDANCE_H

#include <move/Move.h>

class RainDance : public Move {
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
    string name() const override;

    string desc() const override {
        return "祈求下雨。全场开始下雨，提升水类技能伤害，降低火类技能伤害。";
    }

    MoveCat move_cat() const override {
        return MCWater;
    }
};


#endif //YAPOKEMON_RAINDANCE_H
