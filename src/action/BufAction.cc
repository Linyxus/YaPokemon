//
// Created by Yichen Xu on 2020/9/2.
//

#include <action/BufAction.h>
#include <utility>

BufAction::BufAction(shared_ptr<Buff> b, ActionTarget target) {
    _buff = std::move(b);
    _target = target;
}

ActionType BufAction::type() const {
    return ActBuf;
}

ActionTarget BufAction::target() const {
    return _target;
}

