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
};


#endif //POKEMON_CORE_THUNDER_H
