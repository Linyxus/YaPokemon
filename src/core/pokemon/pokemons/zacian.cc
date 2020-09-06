//
// Created by Yichen Xu on 2020/9/5.
//

#include "include/core/pokemon/pokemons/zacian.h"
#include <move/moves/SwordsDance.h>
#include <move/moves/GigaImpact.h>
#include <move/moves/QuickGuard.h>
#include <move/moves/SacredBlade.h>

std::string Zacian::name() const {
    return "苍响";
}

Hexagon<llint> Zacian::base() const {
    return {
            10,
            30,
            10,
            10,
            10,
            30
    };
}

PokemonId Zacian::id() const {
    return PokemonZacian;
}

std::vector<shared_ptr<Move>> Zacian::moves() const {
    return {
            make_shared<SwordsDance>(), make_shared<GigaImpact>(), make_shared<QuickGuard>(),
            make_shared<SacredBlade>()
    };
}

std::vector<int> Zacian::move_weights() const {
    return {30, 60, 30, 50};
}
