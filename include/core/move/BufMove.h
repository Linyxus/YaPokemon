//
// Created by Yichen Xu on 2020/9/2.
//

#ifndef POKEMON_CORE_BUFMOVE_H
#define POKEMON_CORE_BUFMOVE_H

#include <move/Move.h>
#include <buff/Buff.h>

class BufMove : public Move {
public:
    BufMove(shared_ptr<Buff> buff, ActionTarget target);

    ~BufMove() = default;

    shared_ptr<Buff> buff;
    ActionTarget target;

    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
    Actions buf_action(ActionTarget t) const;
};

#endif //POKEMON_CORE_BUFMOVE_H
