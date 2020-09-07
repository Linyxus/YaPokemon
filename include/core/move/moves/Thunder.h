//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_THUNDER_H
#define POKEMON_CORE_THUNDER_H

#include <move/SpAttackMove.h>

class Thunder : public SpAttackMove {
public:
    Thunder();
    ~Thunder() = default;

    [[nodiscard]] string name() const override;

    string desc() const override {
        return "用雷电攻击对手，造成大量伤害。";
    }
};


#endif //POKEMON_CORE_THUNDER_H
