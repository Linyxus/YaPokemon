//
// Created by Yichen Xu on 2020/9/2.
//

#ifndef POKEMON_CORE_CHARGE_H
#define POKEMON_CORE_CHARGE_H

#include <move/BufMove.h>

class Charge : public BufMove {
public:
    Charge();
    ~Charge() = default;

    string name() const override;

    string desc() const override {
        return "充电准备攻击，大幅提升特攻。";
    }

    MoveCat move_cat() const override {
        return MCThunder;
    }
};

#endif //POKEMON_CORE_CHARGE_H
