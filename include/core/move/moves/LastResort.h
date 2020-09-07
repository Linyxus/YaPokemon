//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_LASTRESORT_H
#define YAPOKEMON_LASTRESORT_H

#include <move/AttackMove.h>

class LastResort : public AttackMove {
public:
    LastResort();
    ~LastResort() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;

    string desc() const override {
        return "用力撞向对手，造成大量伤害，自己也要承受伤害的一半";
    }
};


#endif //YAPOKEMON_LASTRESORT_H
