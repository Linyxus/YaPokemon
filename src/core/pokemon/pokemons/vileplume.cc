//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/pokemon/pokemons/vileplume.h"
#include <move/moves/SweetScent.h>
#include <move/moves/GigaDrain.h>
#include <move/moves/Bite.h>
#include <move/moves/LastResort.h>

std::string Vileplume::name() const {
    return "霸王花";
}

Hexagon<llint> Vileplume::base() const {
    return {
            12,
            5,
            15,
            8,
            15,
            8
    };
}

PokemonId Vileplume::id() const {
    return PokemonVileplume;
}

std::vector<shared_ptr<Move>> Vileplume::moves() const {
    return {
            make_shared<SweetScent>(),
            make_shared<GigaDrain>(),
            make_shared<Bite>(),
            make_shared<LastResort>()
    };
}

std::vector<int> Vileplume::move_weights() const {
    return { 10, 12, 5, 3 };
}
