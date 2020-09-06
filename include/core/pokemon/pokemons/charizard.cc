//
// Created by Yichen Xu on 2020/9/6.
//

#include "charizard.h"
#include <move/moves/Inferno.h>
#include <move/moves/FlameWheel.h>
#include <move/moves/FireThrower.h>
#include <move/moves/DragonClaw.h>

std::string Charizard::name() const {
    return "喷火龙";
}

Hexagon<llint> Charizard::base() const {
    return {
            15,
            5,
            5,
            18,
            6,
            15
    };
}

PokemonId Charizard::id() const {
    return PokemonCharizard;
}

std::vector<shared_ptr<Move>> Charizard::moves() const {
    return {
            make_shared<Inferno>(),
            make_shared<FlameWheel>(),
            make_shared<FireThrower>(),
            make_shared<DragonClaw>()
    };
}

std::vector<int> Charizard::move_weights() const {
    return { 10, 6, 8, 5 };
}
