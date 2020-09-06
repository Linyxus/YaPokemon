//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_HAXORUS_H
#define YAPOKEMON_HAXORUS_H

#include <pokemon/PokemonTemplate.h>

class Haxorus : public AttackPokemonTemplate {
public:
    Haxorus() = default;
    ~Haxorus() = default;

    std::string name() const override;
    Hexagon<llint> base() const override;
    PokemonId id() const override;

    std::vector<shared_ptr<Move>> moves() const override;
    std::vector<int> move_weights() const override;
};


#endif //YAPOKEMON_HAXORUS_H
