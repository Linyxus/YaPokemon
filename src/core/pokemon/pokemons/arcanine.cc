//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/pokemon/pokemons/arcanine.h"
#include <move/moves/FireThrower.h>
#include <move/moves/FlameWheel.h>
#include <move/moves/QuickGuard.h>
#include <move/moves/Bite.h>

std::string Arcanine::name() const {
    return "风速狗";
}

Hexagon<llint> Arcanine::base() const {
    return {
            15,
            10,
            10,
            10,
            10,
            15
    };
}

PokemonId Arcanine::id() const {
    return PokemonArcanine;
}

std::vector<shared_ptr<Move>> Arcanine::moves() const {
    return {
            make_shared<FireThrower>(),
            make_shared<FlameWheel>(),
            make_shared<QuickGuard>(),
            make_shared<Bite>()
    };
}

std::vector<int> Arcanine::move_weights() const {
    return { 2, 3, 2, 2 };
}
