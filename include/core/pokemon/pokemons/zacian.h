//
// Created by Yichen Xu on 2020/9/5.
//

#ifndef YAPOKEMON_ZACIAN_H
#define YAPOKEMON_ZACIAN_H

#include <pokemon/PokemonTemplate.h>

class Zacian : public SuperPokemonTemplate {
public:
    Zacian() = default;
    ~Zacian() = default;

    std::string name() const override;
    Hexagon<llint> base() const override;
    PokemonId id() const override;

    std::vector<shared_ptr<Move>> moves() const override;
    std::vector<int> move_weights() const override;
};


#endif //YAPOKEMON_ZACIAN_H
