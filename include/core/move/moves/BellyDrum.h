//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_BELLYDRUM_H
#define YAPOKEMON_BELLYDRUM_H

#include <move/BufMove.h>

class BellyDrum : public BufMove {
public:
    BellyDrum();
    ~BellyDrum() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
};


#endif //YAPOKEMON_BELLYDRUM_H
