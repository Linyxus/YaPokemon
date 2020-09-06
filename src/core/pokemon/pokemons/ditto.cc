//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/pokemon/pokemons/ditto.h"
#include <move/moves/Mimic.h>

std::string Ditto::name() const {
    return "百变怪";
}

Hexagon<llint> Ditto::base() const {
    return {
        10,
        10,
        10,
        10,
        10,
        10
    };
}

PokemonId Ditto::id() const {
    return PokemonDitto;
}

std::vector<shared_ptr<Move>> Ditto::moves() const {
    return { make_shared<Mimic>() };
}
