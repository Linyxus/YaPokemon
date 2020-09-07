//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_BODYSLAM_H
#define YAPOKEMON_BODYSLAM_H

#include <move/AttackMove.h>

class BodySlam : public AttackMove {
public:
    BodySlam();
    ~BodySlam() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;

    string desc() const override {
        return "将全身的重量压在对手身上，造成大量伤害。生命值越高，伤害越高。";
    }
};


#endif //YAPOKEMON_BODYSLAM_H
