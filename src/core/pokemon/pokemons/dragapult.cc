//
// Created by Yichen Xu on 2020/9/6.
//

#include "pokemon/pokemons/dragapult.h"
#include <move/moves/DragonDance.h>
#include <move/moves/DragonDart.h>
#include <move/moves/LastResort.h>

std::string Dragapult::name() const {
    return "多龙";
}

Hexagon<llint> Dragapult::base() const {
    return {
            5,
            20,
            5,
            5,
            5,
            20
    };
}

PokemonId Dragapult::id() const {
    return PokemonDragapult;
}

std::vector<shared_ptr<Move>> Dragapult::moves() const {
    return {
            make_shared<DragonDance>(),
            make_shared<DragonDart>(),
            make_shared<LastResort>()
    };
}

std::vector<int> Dragapult::move_weights() const {
    return { 2, 3, 1 };
}
