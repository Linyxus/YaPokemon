//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_ARCANINE_H
#define YAPOKEMON_ARCANINE_H

#include <pokemon/PokemonTemplate.h>

class Arcanine : public SpeedPokemonTemplate {
public:
    Arcanine() = default;
    ~Arcanine() = default;

    std::string name() const override;
    Hexagon<llint> base() const override;
    PokemonId id() const override;

    std::vector<shared_ptr<Move>> moves() const override;
    std::vector<int> move_weights() const override;
};


#endif //YAPOKEMON_ARCANINE_H
