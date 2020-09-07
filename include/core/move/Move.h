//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_MOVE_H
#define POKEMON_CORE_MOVE_H

#include <action/Action.h>
#include <pokemon/PokemonInstance.h>
#include <memory>
#include <string>
using std::shared_ptr;
using std::string;

class Move {
public:
    Move() = default;
    ~Move() = default;

    virtual Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) = 0;
    virtual string name() const = 0;
    virtual string desc() const = 0;
    virtual MoveCat move_cat() const = 0;
};

#endif //POKEMON_CORE_MOVE_H
