//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_SNORLAX_H
#define YAPOKEMON_SNORLAX_H

#include <pokemon/PokemonTemplate.h>

class Snorlax : public HpPokemonTemplate {
public:
    Snorlax() = default;
    ~Snorlax() = default;

    std::string name() const override;
    Hexagon<llint> base() const override;
    PokemonId id() const override;

    std::vector<shared_ptr<Move>> moves() const override;
    std::vector<int> move_weights() const override;
};


#endif //YAPOKEMON_SNORLAX_H
