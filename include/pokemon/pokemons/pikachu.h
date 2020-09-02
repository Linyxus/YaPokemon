//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_PIKACHU_H
#define POKEMON_CORE_PIKACHU_H

#include <pokemon/PokemonTemplate.h>

class Pikachu : public SpAttackPokemonTemplate {
public:
    Pikachu() = default;
    ~Pikachu() = default;

    std::string name() const override;
    Hexagon<uint> base() const override;
    PokemonId id() const override;

    std::vector<shared_ptr<Move>> moves() const override;
};


#endif //POKEMON_CORE_PIKACHU_H
