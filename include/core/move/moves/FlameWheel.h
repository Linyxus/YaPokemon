//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_FLAMEWHEEL_H
#define YAPOKEMON_FLAMEWHEEL_H

#include <move/AttackMove.h>

class FlameWheel : public AttackMove {
public:
    FlameWheel();
    ~FlameWheel() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;

    string desc() const override {
        return "燃起火焰撞向对手，造成大量伤害。自己也会承受一半的伤害。";
    }
};


#endif //YAPOKEMON_FLAMEWHEEL_H
