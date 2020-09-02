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
};


#endif //POKEMON_CORE_RISINGVOLTAGE_H
