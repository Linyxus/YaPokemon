//
// Created by Yichen Xu on 2020/9/6.
//

#include "zamazenta.h"
#include <move/moves/LastResort.h>
#include <move/moves/GigaImpact.h>
#include <move/moves/SacredBlade.h>
#include <move/moves/IronDefense.h>

std::string Zamazenta::name() const {
    return "臧然玛特";
}

Hexagon<uint> Zamazenta::base() const {
    return {
            20,
            10,
            20,
            10,
            20,
            10
    };
}

PokemonId Zamazenta::id() const {
    return PokemonZamazenta;
}

std::vector<shared_ptr<Move>> Zamazenta::moves() const {
    return {
            make_shared<LastResort>(),
            make_shared<GigaImpact>(),
            make_shared<SacredBlade>(),
            make_shared<IronDefense>()
    };
}

std::vector<int> Zamazenta::move_weights() const {
    return {1, 3, 2, 3};
}
