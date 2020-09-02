//
// Created by Yichen Xu on 2020/9/1.
//

#include <action/SpAttackAction.h>

SpAttackAction::SpAttackAction(int value, MoveCat attack_type) {
    this->value = value;
    this->attack_type = attack_type;
}

ActionType SpAttackAction::type() const {
    return ActSpAttack;
}

ActionTarget SpAttackAction::target() const {
    return ActTarget;
}
