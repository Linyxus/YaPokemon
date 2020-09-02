//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_BUFACTION_H
#define POKEMON_CORE_BUFACTION_H

#include <action/Action.h>
#include <buff/Buff.h>

class BufAction : public Action {
public:
    BufAction(shared_ptr<Buff> b, ActionTarget target);
    ~BufAction() = default;

    ActionType type() const override;
    ActionTarget target() const override;

    shared_ptr<Buff> _buff;
    ActionTarget _target;
};

#endif //POKEMON_CORE_BUFACTION_H
