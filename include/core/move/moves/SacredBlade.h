//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_SACREDBLADE_H
#define YAPOKEMON_SACREDBLADE_H

#include <move/SpAttackMove.h>

class SacredBlade : public SpAttackMove {
public:
    SacredBlade();
    ~SacredBlade() = default;

    string name() const override;
};


#endif //YAPOKEMON_SACREDBLADE_H
