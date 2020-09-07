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

    string desc() const override {
        return "散发出香甜的气味。恢复自身最大生命值的五分之一，恢复对手最大生命值十分之一。让对手沉醉于这种气味，降低特防。";
    }

    MoveCat move_cat() const override {
        return MCGrass;
    }
};


#endif //YAPOKEMON_SWEETSCENT_H
