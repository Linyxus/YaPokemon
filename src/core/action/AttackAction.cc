//
// Created by Yichen Xu on 2020/9/1.
//

#include <action/AttackAction.h>

AttackAction::AttackAction(int value, MoveCat attack_type, ActionTarget target) {
    this->value = value;
    this->attack_type = attack_type;
    this->_target = target;
}

ActionType AttackAction::type() const {
    return ActAttack;
}

ActionTarget AttackAction::target() const {
    return _target;
}
