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
};


#endif //YAPOKEMON_SWORDSDANCE_H
