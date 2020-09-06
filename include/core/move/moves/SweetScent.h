//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_SWEETSCENT_H
#define YAPOKEMON_SWEETSCENT_H

#include <move/BufMove.h>

class SweetScent : public BufMove {
public:
    SweetScent();

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
};


#endif //YAPOKEMON_SWEETSCENT_H
