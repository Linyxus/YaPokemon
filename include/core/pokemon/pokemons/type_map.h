//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_TYPE_MAP_H
#define POKEMON_CORE_TYPE_MAP_H

#include <pokemon/def.h>
#include <pokemon/Pokemon.h>
#include <pokemon/pokemons/eevee.h>
#include <pokemon/pokemons/pikachu.h>
#include <pokemon/pokemons/zacian.h>
#include <pokemon/pokemons/dragapult.h>
#include <pokemon/pokemons/zamazenta.h>

template<PokemonId i>
struct pokemon_of;

template<>
struct pokemon_of<PokemonEevee> {
    typedef Eevee type;
};

template<>
struct pokemon_of<PokemonPikachu> {
    typedef Pikachu type;
};

template<>
struct pokemon_of<PokemonZacian> {
    typedef Zacian type;
};

template<>
struct pokemon_of<PokemonDragapult> {
    typedef Dragapult type;
};

template<>
struct pokemon_of<PokemonZamazenta> {
    typedef Zamazenta type;
};

#endif //POKEMON_CORE_TYPE_MAP_H
