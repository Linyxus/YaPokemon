//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_BITE_H
#define POKEMON_CORE_BITE_H

#include <move/AttackMove.h>

class Bite : public AttackMove {
public:
    Bite();
    ~Bite() = default;

    string name() const override;
};

#endif //POKEMON_CORE_BITE_H
