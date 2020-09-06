//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_ATTACKACTION_H
#define POKEMON_CORE_ATTACKACTION_H

#include <action/Action.h>
#include <types/move.h>
#include <common.h>

class AttackAction : public Action {
public:
    AttackAction(int value, MoveCat attack_type, ActionTarget target = ActTarget);
    ~AttackAction() = default;

    ActionType type() const override;
    ActionTarget target() const override;

    llint value;
    MoveCat attack_type;
    ActionTarget _target;
};

#endif //POKEMON_CORE_ATTACKACTION_H
