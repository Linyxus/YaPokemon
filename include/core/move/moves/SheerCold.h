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
};


#endif //YAPOKEMON_SHEERCOLD_H
