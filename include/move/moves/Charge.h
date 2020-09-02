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
};

#endif //POKEMON_CORE_CHARGE_H
