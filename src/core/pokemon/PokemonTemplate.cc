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

Hexagon<uint> SuperPokemonTemplate::growth() const {
    return {
        3,
        3,
        3,
        3,
        3,
        3
    };
}

PokemonType SuperPokemonTemplate::type() const {
    return PTSuper;
}

Hexagon<uint> AttackPokemonTemplate::growth() const {
    return {
            1,
            5,
            1,
            1,
            2,
            2
    };
}

PokemonType AttackPokemonTemplate::type() const {
    return PTAttack;
}

Hexagon<uint> DefensePokemonTemplate::growth() const {
    return {
        2,
        1,
        4,
        1,
        4,
        1
    };
}

PokemonType DefensePokemonTemplate::type() const {
    return PTDefense;
}

Hexagon<uint> HpPokemonTemplate::growth() const {
    return {
        7,
        1,
        1,
        1,
        1,
        1
    };
}

PokemonType HpPokemonTemplate::type() const {
    return PTHp;
}

Hexagon<uint> SpeedPokemonTemplate::growth() const {
    return {
        1,
        3,
        1,
        2,
        1,
        4
    };
}

PokemonType SpeedPokemonTemplate::type() const {
    return PTSpeed;
}
