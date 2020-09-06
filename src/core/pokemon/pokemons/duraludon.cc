//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/pokemon/pokemons/duraludon.h"
#include <move/moves/IceBeam.h>
#include <move/moves/IronDefense.h>
#include <move/moves/DragonDance.h>
#include <move/moves/DragonDart.h>

std::string Duraludon::name() const {
    return "铝钢龙";
}

Hexagon<llint> Duraludon::base() const {
    return {
            15,
            5,
            12,
            12,
            12,
            8
    };
}

PokemonId Duraludon::id() const {
    return PokemonDuraludon;
}

std::vector<shared_ptr<Move>> Duraludon::moves() const {
    return {
            make_shared<IceBeam>(),
            make_shared<IronDefense>(),
            make_shared<DragonDance>(),
            make_shared<DragonDart>()
    };
}

std::vector<int> Duraludon::move_weights() const {
    return {
        5, 4, 2, 2
    };
}
