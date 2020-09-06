//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_LASTRESORT_H
#define YAPOKEMON_LASTRESORT_H

#include <move/AttackMove.h>

class LastResort : public AttackMove {
public:
    LastResort();
    ~LastResort() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
};


#endif //YAPOKEMON_LASTRESORT_H
