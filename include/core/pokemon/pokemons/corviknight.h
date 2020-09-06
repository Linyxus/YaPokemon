//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_CORVIKNIGHT_H
#define YAPOKEMON_CORVIKNIGHT_H

#include <pokemon/PokemonTemplate.h>

class Corviknight : public AttackPokemonTemplate {
public:
    Corviknight() = default;
    ~Corviknight() = default;

    std::string name() const override;
    Hexagon<llint> base() const override;
    PokemonId id() const override;

    std::vector<shared_ptr<Move>> moves() const override;
    std::vector<int> move_weights() const override;
};


#endif //YAPOKEMON_CORVIKNIGHT_H
