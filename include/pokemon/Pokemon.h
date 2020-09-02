//
// Created by Yichen Xu on 2020/8/28.
//

#ifndef POKEMON_CORE_POKEMON_H
#define POKEMON_CORE_POKEMON_H

#include <pokemon/PokemonTemplate.h>
#include <common.h>
#include <algorithm>

class Pokemon {
public:
    Pokemon() = default;
    ~Pokemon() = default;

    virtual std::string name() const = 0;
    virtual uint level() const = 0;
    virtual Hexagon<uint> max() const = 0;

    virtual void learn(uint exp) = 0;
    virtual const BasePokemonTemplate *temp() const = 0;
};

template <typename T>
class PokemonOf : public Pokemon {
public:
    PokemonOf();
    ~PokemonOf() = default;

    std::string name() const override;
    uint level() const override;
    Hexagon<uint> max() const override;

    void learn(uint exp) override;
    const BasePokemonTemplate * temp() const override;
private:
    T _template;
    uint _exp;
};

template<typename T>
PokemonOf<T>::PokemonOf()
 : _template(), _exp(0) {}

template<typename T>
std::string PokemonOf<T>::name() const {
    return _template.name();
}

template<typename T>
uint PokemonOf<T>::level() const {
    uint x = _exp / 50;
    return x > 15 ? 15 : x;
}

template<typename T>
Hexagon<uint> PokemonOf<T>::max() const {
    uint l = level();
    return Hexagon<uint> {
        _template.base().hp + _template.growth().hp * l,
        _template.base().attack + _template.growth().attack * l,
        _template.base().defense + _template.growth().defense * l,
        _template.base().spAttack + _template.growth().spAttack * l,
        _template.base().spDefense + _template.growth().spDefense * l,
        _template.base().speed + _template.growth().speed * l
    };
}

template<typename T>
void PokemonOf<T>::learn(uint exp) {
    _exp += exp;
}

template<typename T>
const BasePokemonTemplate *PokemonOf<T>::temp() const {
    return &_template;
}

#endif //POKEMON_CORE_POKEMON_H
