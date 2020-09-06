//
// Created by Yichen Xu on 2020/9/2.
//

#include <move/BufMove.h>
#include <action/BufAction.h>
#include <utility>

BufMove::BufMove(shared_ptr<Buff> buff, ActionTarget target) {
    this->buff = std::move(buff);
    this->target = target;
}

Actions BufMove::move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) {
    return buf_action(this->target);
}

Actions BufMove::buf_action(ActionTarget t) const {
    return {
        make_shared<BufAction>(buff, t)
    };
}

