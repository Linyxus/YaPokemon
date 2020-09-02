//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_SPATTACKACTION_H
#define POKEMON_CORE_SPATTACKACTION_H

#include <action/Action.h>
#include <types/move.h>


class SpAttackAction : public Action {
public:
    SpAttackAction(int value, MoveCat attack_type);
    ~SpAttackAction() = default;

    ActionType type() const override;
    ActionTarget target() const override;

    int value;
    MoveCat attack_type;
};


#endif //POKEMON_CORE_SPATTACKACTION_H
