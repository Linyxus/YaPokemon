//
// Created by Yichen Xu on 2020/8/28.
//

#ifndef POKEMON_CORE_POKEMONTEMPLATE_H
#define POKEMON_CORE_POKEMONTEMPLATE_H

#include <common.h>
#include <string>
#include <vector>
#include <pokemon/Hexagon.h>
#include <types/pokemon.h>
#include <memory>
#include <pokemon/def.h>
using std::shared_ptr;

class Move;

class BasePokemonTemplate {
public:
    BasePokemonTemplate() = default;
    ~BasePokemonTemplate() = default;

    virtual PokemonId id() const = 0;

    virtual Hexagon<uint> growth() const = 0;
    virtual Hexagon<uint> base() const = 0;

    virtual std::string name() const = 0;
    virtual PokemonType type() const = 0;

    virtual std::vector<shared_ptr<Move>> moves() const = 0;
};

class NormalPokemonTemplate : public BasePokemonTemplate {
public:
    NormalPokemonTemplate() = default;
    ~NormalPokemonTemplate() = default;

    Hexagon<uint> growth() const override;
    PokemonType type() const override;
};

class SpAttackPokemonTemplate : public BasePokemonTemplate {
public:
    SpAttackPokemonTemplate() = default;
    ~SpAttackPokemonTemplate() = default;

    Hexagon<uint> growth() const override;
    PokemonType type() const override;
};

#endif //POKEMON_CORE_POKEMONTEMPLATE_H
