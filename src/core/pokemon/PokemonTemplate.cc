//
// Created by Yichen Xu on 2020/8/28.
//

#include "pokemon/PokemonTemplate.h"

PokemonType NormalPokemonTemplate::type() const {
    return PTNormal;
}

Hexagon<uint> NormalPokemonTemplate::growth() const {
    return Hexagon<uint> {
        2,
        2,
        2,
        2,
        2,
        2
    };
}

PokemonType SpAttackPokemonTemplate::type() const {
    return PTSpAttack;
}

Hexagon<uint> SpAttackPokemonTemplate::growth() const {
    return {
        1,
        1,
        1,
        5,
        2,
        2
    };
}
