//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_DEF_H
#define POKEMON_CORE_DEF_H

#include <common.h>

enum PokemonId {
    PokemonEevee,
    PokemonPikachu
};

const int PokemonNum = 2;

inline PokemonId rand_pokemon() {
    return static_cast<PokemonId>(randint(0, PokemonNum));
}

#endif //POKEMON_CORE_DEF_H
