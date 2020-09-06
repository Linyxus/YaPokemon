//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_MIMIC_H
#define YAPOKEMON_MIMIC_H

#include <move/Move.h>


class Mimic : public Move {
public:
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
    string name() const override;
};


#endif //YAPOKEMON_MIMIC_H
