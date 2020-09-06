//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/pokemon/pokemons/corviknight.h"
#include <move/moves/DrillPeck.h>
#include <move/moves/Pluck.h>
#include <move/moves/Sleep.h>
#include <move/moves/QuickGuard.h>

std::string Corviknight::name() const {
    return "钢铠鸦";
}

Hexagon<llint> Corviknight::base() const {
    return {
            8,
            20,
            8,
            5,
            8,
            15
    };
}

PokemonId Corviknight::id() const {
    return PokemonCorviknight;
}

std::vector<shared_ptr<Move>> Corviknight::moves() const {
    return {
            make_shared<DrillPeck>(),
            make_shared<Pluck>(),
            make_shared<Sleep>(),
            make_shared<QuickGuard>()
    };
}

std::vector<int> Corviknight::move_weights() const {
    return { 10, 12, 6, 6 };
}
