//
// Created by Yichen Xu on 2020/8/29.
//

#ifndef POKEMON_CORE_EEVEE_H
#define POKEMON_CORE_EEVEE_H

#include <pokemon/PokemonTemplate.h>
#include <memory>
using std::shared_ptr;

class Eevee : public NormalPokemonTemplate {
public:
    Eevee() = default;
    ~Eevee() = default;

    std::string name() const override;
    Hexagon<uint> base() const override;
    PokemonId id() const override;

    std::vector<shared_ptr<Move>> moves() const override;
};

#endif //POKEMON_CORE_EEVEE_H
