//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/action/HealAction.h"

HealAction::HealAction(int value, ActionTarget t) : value(value), _target(t) {}

ActionType HealAction::type() const {
    return ActHeal;
}

ActionTarget HealAction::target() const {
    return _target;
}
