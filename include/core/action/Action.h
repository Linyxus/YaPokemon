//
// Created by Yichen Xu on 2020/8/30.
//

#ifndef POKEMON_CORE_ACTION_H
#define POKEMON_CORE_ACTION_H

#include <vector>
#include <memory>

enum ActionType {
    ActNop,
    ActAttack,
    ActSpAttack,
    ActHeal,
    ActBuf
};

enum ActionTarget {
    ActSelf,
    ActTarget
};

class Action {
public:
    Action() = default;
    ~Action() = default;

    virtual ActionType type() const = 0;
    virtual ActionTarget target() const = 0;
};

using Actions = std::vector<std::shared_ptr<Action>>;

#endif //POKEMON_CORE_ACTION_H
