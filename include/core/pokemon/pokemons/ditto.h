//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_DITTO_H
#define YAPOKEMON_DITTO_H

#include <pokemon/PokemonTemplate.h>

class Ditto : public NormalPokemonTemplate {
public:
    std::string name() const override;
    Hexagon<llint> base() const override;
    PokemonId id() const override;

    std::vector<shared_ptr<Move>> moves() const override;
};


#endif //YAPOKEMON_DITTO_H
