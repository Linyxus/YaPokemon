//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_ZAMAZENTA_H
#define YAPOKEMON_ZAMAZENTA_H

#include <pokemon/PokemonTemplate.h>

class Zamazenta : public SuperPokemonTemplate {
public:
    Zamazenta() = default;
    ~Zamazenta() = default;

    std::string name() const override;
    Hexagon<llint> base() const override;
    PokemonId id() const override;

    std::vector<shared_ptr<Move>> moves() const override;
    std::vector<int> move_weights() const override;
};


#endif //YAPOKEMON_ZAMAZENTA_H
