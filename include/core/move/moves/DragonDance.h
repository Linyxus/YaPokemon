//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_DRAGONDANCE_H
#define YAPOKEMON_DRAGONDANCE_H

#include <move/BufMove.h>

class DragonDance : public BufMove {
public:
    DragonDance();
    ~DragonDance() = default;

    string name() const override;

    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
};


#endif //YAPOKEMON_DRAGONDANCE_H
