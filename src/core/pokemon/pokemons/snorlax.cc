//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/pokemon/pokemons/snorlax.h"
#include <move/moves/BellyDrum.h>
#include <move/moves/BodySlam.h>
#include <move/moves/LastResort.h>
#include <move/moves/Sleep.h>

std::string Snorlax::name() const {
    return "卡比兽";
}

Hexagon<llint> Snorlax::base() const {
    return {
            15,
            8,
            12,
            8,
            12,
            8
    };
}

PokemonId Snorlax::id() const {
    return PokemonSnorlax;
}

std::vector<shared_ptr<Move>> Snorlax::moves() const {
    return {
            make_shared<BellyDrum>(),
            make_shared<BodySlam>(),
            make_shared<LastResort>(),
            make_shared<Sleep>()
    };
}

std::vector<int> Snorlax::move_weights() const {
    return { 5, 8, 3, 5 };
}
