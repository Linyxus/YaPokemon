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

    string desc() const override {
        return "休息一下。恢复最大生命值的五分之一。";
    }

    MoveCat move_cat() const override {
        return MCNormal;
    }
};


#endif //YAPOKEMON_SLEEP_H
