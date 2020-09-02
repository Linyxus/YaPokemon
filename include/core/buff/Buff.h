//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_BUFF_H
#define POKEMON_CORE_BUFF_H

#include <common.h>
#include <action/Action.h>
#include <pokemon/Hexagon.h>
#include <memory>
#include <string>
using namespace std;

class Buff {
public:
    Buff() = default;
    ~Buff() = default;

    virtual void map_action(const std::shared_ptr<Action> &action) = 0;
    virtual Hexagon<uint> map_current(const Hexagon<uint> &current) = 0;
    virtual bool expire() const = 0;

    virtual string name() const = 0;

    virtual void tick() = 0;
};

#endif //POKEMON_CORE_BUFF_H
