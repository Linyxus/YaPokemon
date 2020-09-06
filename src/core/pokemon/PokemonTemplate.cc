//
// Created by Yichen Xu on 2020/8/28.
//

#include "pokemon/PokemonTemplate.h"

PokemonType NormalPokemonTemplate::type() const {
    return PTNormal;
}

Hexagon<llint> NormalPokemonTemplate::growth() const {
    return Hexagon<llint> {
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

Hexagon<llint> SpAttackPokemonTemplate::growth() const {
    return {
        1,
        1,
        1,
        5,
        2,
        2
    };
}

Hexagon<llint> SuperPokemonTemplate::growth() const {
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

Hexagon<llint> AttackPokemonTemplate::growth() const {
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

Hexagon<llint> DefensePokemonTemplate::growth() const {
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

Hexagon<llint> HpPokemonTemplate::growth() const {
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

Hexagon<llint> SpeedPokemonTemplate::growth() const {
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
