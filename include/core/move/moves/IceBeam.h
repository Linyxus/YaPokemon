//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_ICEBEAM_H
#define YAPOKEMON_ICEBEAM_H

#include <move/SpAttackMove.h>

class IceBeam : public SpAttackMove {
public:
    IceBeam();
    ~IceBeam() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
};


#endif //YAPOKEMON_ICEBEAM_H
