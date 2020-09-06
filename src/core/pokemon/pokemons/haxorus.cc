//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/pokemon/pokemons/haxorus.h"
#include <move/moves/DragonClaw.h>
#include <move/moves/Outrage.h>
#include <move/moves/DragonDance.h>
#include <move/moves/QuickGuard.h>

std::string Haxorus::name() const {
    return "双斧战龙";
}

Hexagon<llint> Haxorus::base() const {
    return {
            8,
            20,
            8,
            5,
            8,
            12
    };
}

PokemonId Haxorus::id() const {
    return PokemonHaxorus;
}

std::vector<shared_ptr<Move>> Haxorus::moves() const {
    return {
            make_shared<DragonClaw>(),
            make_shared<Outrage>(),
            make_shared<DragonDance>(),
            make_shared<QuickGuard>()
    };
}

std::vector<int> Haxorus::move_weights() const {
    return {
        8,
        8,
        6,
        5
    };
}
