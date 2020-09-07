//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_DRAGONDANCE_H
#define YAPOKEMON_DRAGONDANCE_H

#include <move/BufMove.h>

class DragonDance : public BufMove {
public:
    DragonDance();
    ~DragonDance() = default;

    string name() const override;

    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;

    string desc() const override {
        return "跳起龙族的舞蹈。大幅提升龙类技能伤害。";
    }

    MoveCat move_cat() const override {
        return MCDragon;
    }
};


#endif //YAPOKEMON_DRAGONDANCE_H
