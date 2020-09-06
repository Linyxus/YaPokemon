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
#include <pokemon/pokemons/arcanine.h>
#include <pokemon/pokemons/snorlax.h>
#include <pokemon/pokemons/duraludon.h>
#include <pokemon/pokemons/haxorus.h>
#include <pokemon/pokemons/corviknight.h>
#include <pokemon/pokemons/charizard.h>
#include <pokemon/pokemons/vileplume.h>
#include <pokemon/pokemons/lapras.h>
#include <pokemon/pokemons/ditto.h>

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

template<>
struct pokemon_of<PokemonArcanine> {
    typedef Arcanine type;
};

template<>
struct pokemon_of<PokemonSnorlax> {
    typedef Snorlax type;
};

template<>
struct pokemon_of<PokemonDuraludon> {
    typedef Duraludon type;
};

template<>
struct pokemon_of<PokemonHaxorus> {
    typedef Haxorus type;
};

template<>
struct pokemon_of<PokemonCorviknight> {
    typedef Corviknight type;
};

template<>
struct pokemon_of<PokemonCharizard> {
    typedef Charizard type;
};

template<>
struct pokemon_of<PokemonVileplume> {
    typedef Vileplume type;
};

template<>
struct pokemon_of<PokemonLapras> {
    typedef Lapras type;
};

template<>
struct pokemon_of<PokemonDitto> {
    typedef Ditto type;
};

#endif //POKEMON_CORE_TYPE_MAP_H
