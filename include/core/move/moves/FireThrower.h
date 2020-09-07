//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_FIRETHROWER_H
#define YAPOKEMON_FIRETHROWER_H

#include <move/SpAttackMove.h>

class FireThrower : public SpAttackMove {
public:
    FireThrower();
    ~FireThrower() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;

    string desc() const override {
        return "喷射火焰，造成大量伤害，并能灼伤对手降低特防";
    }
};


#endif //YAPOKEMON_FIRETHROWER_H
