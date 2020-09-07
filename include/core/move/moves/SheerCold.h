//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_SHEERCOLD_H
#define YAPOKEMON_SHEERCOLD_H

#include <move/Move.h>

class SheerCold : public Move {
public:
    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;

    string desc() const override {
        return "将温度降到绝对零度。有一定概率直接秒杀对手。";
    }

    MoveCat move_cat() const override {
        return MCIce;
    }
};


#endif //YAPOKEMON_SHEERCOLD_H
