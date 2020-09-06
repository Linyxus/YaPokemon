//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_INFERNO_H
#define YAPOKEMON_INFERNO_H

#include <move/SpAttackMove.h>

class Inferno : public SpAttackMove {
public:
    Inferno();
    ~Inferno() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
};


#endif //YAPOKEMON_INFERNO_H
