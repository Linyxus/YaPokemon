//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_CHARIZARD_H
#define YAPOKEMON_CHARIZARD_H

#include <pokemon/PokemonTemplate.h>

class Charizard : public SpAttackPokemonTemplate {
public:
    Charizard() = default;
    ~Charizard() = default;

    std::string name() const override;
    Hexagon<llint> base() const override;
    PokemonId id() const override;

    std::vector<shared_ptr<Move>> moves() const override;
    std::vector<int> move_weights() const override;
};


#endif //YAPOKEMON_CHARIZARD_H
