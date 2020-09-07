//
// Created by Yichen Xu on 2020/9/2.
//

#ifndef POKEMON_CORE_RISINGVOLTAGE_H
#define POKEMON_CORE_RISINGVOLTAGE_H

#include <move/BufMove.h>

class RisingVoltage : public BufMove {
public:
    RisingVoltage();
    ~RisingVoltage() = default;

    string name() const override;

    string desc() const override {
        return "强行增加电压。大幅提升电类技能伤害";
    }

    MoveCat move_cat() const override {
        return MCThunder;
    }
};


#endif //POKEMON_CORE_RISINGVOLTAGE_H
