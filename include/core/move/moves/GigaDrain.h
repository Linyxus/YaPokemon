//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_GIGADRAIN_H
#define YAPOKEMON_GIGADRAIN_H

#include <move/SpAttackMove.h>

class GigaDrain : public SpAttackMove {
public:
    GigaDrain();

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;

    string desc() const override {
        return "大幅吸取对手生命值";
    }
};


#endif //YAPOKEMON_GIGADRAIN_H
