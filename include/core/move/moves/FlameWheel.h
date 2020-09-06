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
};


#endif //YAPOKEMON_FLAMEWHEEL_H
