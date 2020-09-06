//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_ATTACKMOVE_H
#define POKEMON_CORE_ATTACKMOVE_H

#include <move/Move.h>
#include <types/move.h>

class AttackMove : public Move {
public:
    AttackMove(llint power, MoveCat cat);
    ~AttackMove() = default;

    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
    Actions attack_action(const shared_ptr<PokemonInstance>& self, ActionTarget t = ActTarget);
    llint power;
    MoveCat cat;
};

#endif //POKEMON_CORE_ATTACKMOVE_H
