//
// Created by Yichen Xu on 2020/8/30.
//

/**
 * Action is a concept that is used in Pokemon battle system.
 * In each battle, pokemons will perform `Move`s which result in a sequence of `Action`s.
 * A action is a transform to be applied on pokemons. It can change damage or heal
 *  current hp, and add buffers.
 */

#ifndef POKEMON_CORE_ACTION_H
#define POKEMON_CORE_ACTION_H

#include <vector>
#include <memory>

/**
 * Type of action.
 */
enum ActionType {
    ActNop,
    ActAttack,
    ActSpAttack,
    ActHeal,
    ActBuf
};

/**
 * Target of action. Self (the performer) or target (the other pokemon in the battle).
 */
enum ActionTarget {
    ActSelf,
    ActTarget
};

/**
 * Abstract base class of actions.
 */
class Action {
public:
    Action() = default;
    ~Action() = default;

    virtual ActionType type() const = 0;
    virtual ActionTarget target() const = 0;
};

using Actions = std::vector<std::shared_ptr<Action>>;

#endif //POKEMON_CORE_ACTION_H
