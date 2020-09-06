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
};


#endif //YAPOKEMON_BRINE_H
