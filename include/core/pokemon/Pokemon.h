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
    virtual llint level() const = 0;
    virtual Hexagon<llint> max() const = 0;

    virtual void learn(llint exp) = 0;
    virtual const BasePokemonTemplate *temp() const = 0;
};

template <typename T>
class PokemonOf : public Pokemon {
public:
    PokemonOf();
    ~PokemonOf() = default;

    std::string name() const override;
    llint level() const override;
    Hexagon<llint> max() const override;

    void learn(llint exp) override;
    const BasePokemonTemplate * temp() const override;
private:
    T _template;
    llint _exp;
};

template<typename T>
PokemonOf<T>::PokemonOf()
 : _template(), _exp(0) {}

template<typename T>
std::string PokemonOf<T>::name() const {
    return _template.name();
}

template<typename T>
llint PokemonOf<T>::level() const {
    llint x = _exp / 50;
    return x > 15 ? 15 : x;
}

template<typename T>
Hexagon<llint> PokemonOf<T>::max() const {
    llint l = level();
    return Hexagon<llint> {
        _template.base().hp + _template.growth().hp * l,
        _template.base().attack + _template.growth().attack * l,
        _template.base().defense + _template.growth().defense * l,
        _template.base().spAttack + _template.growth().spAttack * l,
        _template.base().spDefense + _template.growth().spDefense * l,
        _template.base().speed + _template.growth().speed * l
    };
}

template<typename T>
void PokemonOf<T>::learn(llint exp) {
    _exp += exp;
}

template<typename T>
const BasePokemonTemplate *PokemonOf<T>::temp() const {
    return &_template;
}

#endif //POKEMON_CORE_POKEMON_H
