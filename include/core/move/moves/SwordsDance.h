//
// Created by Yichen Xu on 2020/9/5.
//

#ifndef YAPOKEMON_SWORDSDANCE_H
#define YAPOKEMON_SWORDSDANCE_H

#include <move/BufMove.h>

class SwordsDance : public BufMove {
public:
    SwordsDance();
    ~SwordsDance() = default;

    string name() const override;

    string desc() const override {
        return "舞剑，大幅提升攻击。";
    }

    MoveCat move_cat() const override {
        return MCSacred;
    }
};


#endif //YAPOKEMON_SWORDSDANCE_H
