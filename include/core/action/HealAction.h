//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_HEALACTION_H
#define YAPOKEMON_HEALACTION_H

#include <action/Action.h>

class HealAction : public Action {
public:
    HealAction(int value, ActionTarget t = ActSelf);
    ~HealAction() = default;

    ActionType type() const override;
    ActionTarget target() const override;

    int value;
    ActionTarget _target;
};


#endif //YAPOKEMON_HEALACTION_H
