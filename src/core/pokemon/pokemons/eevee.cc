//
// Created by Yichen Xu on 2020/8/29.
//

#include <pokemon/pokemons/eevee.h>
#include <move/moves/Bite.h>

std::string Eevee::name() const {
    return "伊布";
}

Hexagon<llint> Eevee::base() const {
    return Hexagon<llint> {
            10,
            10,
            10,
            10,
            10,
            10
    };
}

std::vector<shared_ptr<Move>> Eevee::moves() const {
    return {
        make_shared<Bite>()
    };
}

PokemonId Eevee::id() const {
    return PokemonEevee;
}
