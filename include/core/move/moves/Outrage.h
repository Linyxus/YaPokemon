//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_OUTRAGE_H
#define YAPOKEMON_OUTRAGE_H

#include <move/AttackMove.h>

class Outrage : public AttackMove {
public:
    Outrage();
    ~Outrage() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
};


#endif //YAPOKEMON_OUTRAGE_H
