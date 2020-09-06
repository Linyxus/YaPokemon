//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_SLEEP_H
#define YAPOKEMON_SLEEP_H

#include <move/Move.h>

class Sleep : public Move {
public:
    Sleep() = default;
    ~Sleep() = default;

    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
    string name() const override;
};


#endif //YAPOKEMON_SLEEP_H
