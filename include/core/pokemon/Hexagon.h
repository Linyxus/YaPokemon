//
// Created by Yichen Xu on 2020/8/28.
//

#ifndef POKEMON_CORE_HEXAGON_H
#define POKEMON_CORE_HEXAGON_H

template <typename T>
struct Hexagon {
    T hp;
    T attack;
    T defense;
    T spAttack;
    T spDefense;
    T speed;
};

enum AbilityAxis {
    Hp,
    Attack,
    Defense,
    SpAttack,
    SpDefense,
    Speed
};

#endif //POKEMON_CORE_HEXAGON_H
