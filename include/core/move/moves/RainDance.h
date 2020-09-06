//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_RAINDANCE_H
#define YAPOKEMON_RAINDANCE_H

#include <move/Move.h>

class RainDance : public Move {
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
    string name() const override;
};


#endif //YAPOKEMON_RAINDANCE_H
