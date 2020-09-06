//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_IRONDEFENSE_H
#define YAPOKEMON_IRONDEFENSE_H

#include <move/BufMove.h>

class IronDefense : public Move {
public:
    IronDefense() = default;
    ~IronDefense() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
};


#endif //YAPOKEMON_IRONDEFENSE_H
