//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/pokemon/pokemons/lapras.h"
#include <move/moves/SheerCold.h>
#include <move/moves/Brine.h>
#include <move/moves/PerishSong.h>
#include <move/moves/RainDance.h>

std::string Lapras::name() const {
    return "拉普拉斯";
}

Hexagon<llint> Lapras::base() const {
    return {
            12,
            10,
            15,
            10,
            15,
            10
    };
}

PokemonId Lapras::id() const {
    return PokemonLapras;
}

std::vector<shared_ptr<Move>> Lapras::moves() const {
    return {
            make_shared<SheerCold>(),
            make_shared<Brine>(),
            make_shared<PerishSong>(),
            make_shared<RainDance>()
    };
}

std::vector<int> Lapras::move_weights() const {
    return { 3, 4, 5, 3 };
}
