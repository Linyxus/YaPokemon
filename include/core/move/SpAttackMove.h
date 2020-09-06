//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_SPATTACKMOVE_H
#define POKEMON_CORE_SPATTACKMOVE_H

#include <move/Move.h>
#include <types/move.h>

class SpAttackMove : public Move {
public:
    SpAttackMove(llint power, MoveCat cat);
    ~SpAttackMove() = default;

    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
    Actions attack_action(const shared_ptr<PokemonInstance>& self);
    llint power;
    MoveCat cat;
};

#endif //POKEMON_CORE_SPATTACKMOVE_H
