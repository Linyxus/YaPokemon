//
// Created by Yichen Xu on 2020/9/1.
//

#include "pokemon/pokemons/pikachu.h"
#include <move/moves/Thunder.h>
#include <move/moves/Bite.h>
#include <move/moves/Charge.h>
#include <move/moves/RisingVoltage.h>

std::string Pikachu::name() const {
    return "皮卡丘";
}

Hexagon<uint> Pikachu::base() const {
    return {
            8,
            8,
            8,
            20,
            8,
            8
    };
}

PokemonId Pikachu::id() const {
    return PokemonPikachu;
}

std::vector<shared_ptr<Move>> Pikachu::moves() const {
    return {make_shared<Thunder>(),
            make_shared<Charge>(),
            make_shared<RisingVoltage>()};
}

std::vector<int> Pikachu::move_weights() const {
    return { 10, 3, 3 };
}
