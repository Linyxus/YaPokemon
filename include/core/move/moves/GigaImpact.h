//
// Created by Yichen Xu on 2020/9/5.
//

#ifndef YAPOKEMON_GIGAIMPACT_H
#define YAPOKEMON_GIGAIMPACT_H

#include <move/AttackMove.h>

class GigaImpact : public AttackMove {
public:
    GigaImpact();
    ~GigaImpact() = default;

    string name() const override;

    string desc() const override {
        return "用神兽巨大的剑斩向对手，造成巨量伤害。";
    }
};


#endif //YAPOKEMON_GIGAIMPACT_H
