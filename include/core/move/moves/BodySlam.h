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
};


#endif //YAPOKEMON_BODYSLAM_H
