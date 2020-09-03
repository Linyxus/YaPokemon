//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_ATTACKACTION_H
#define POKEMON_CORE_ATTACKACTION_H

#include <action/Action.h>
#include <types/move.h>

class AttackAction : public Action {
public:
    AttackAction(int value, MoveCat attack_type);
    ~AttackAction() = default;

    ActionType type() const override;
    ActionTarget target() const override;

    int value;
    MoveCat attack_type;
};

#endif //POKEMON_CORE_ATTACKACTION_H