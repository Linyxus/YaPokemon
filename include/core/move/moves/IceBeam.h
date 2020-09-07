//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_ICEBEAM_H
#define YAPOKEMON_ICEBEAM_H

#include <move/SpAttackMove.h>

class IceBeam : public SpAttackMove {
public:
    IceBeam();
    ~IceBeam() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;

    string desc() const override {
        return "射出冰冻光线。能够冰冻对手，降低速度";
    }
};


#endif //YAPOKEMON_ICEBEAM_H
