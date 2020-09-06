//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_PLUCK_H
#define YAPOKEMON_PLUCK_H

#include <move/AttackMove.h>

class Pluck : public AttackMove {
public:
    Pluck();
    ~Pluck() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
};


#endif //YAPOKEMON_PLUCK_H
