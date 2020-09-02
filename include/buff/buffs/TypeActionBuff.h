//
// Created by Yichen Xu on 2020/9/2.
//

#ifndef POKEMON_CORE_TYPEACTIONBUFF_H
#define POKEMON_CORE_TYPEACTIONBUFF_H

#include <buff/Buff.h>
#include <types/move.h>

class TypeActionBuff : public Buff {
public:
    TypeActionBuff(MoveCat cat, double rate, uint expire, string name);
    ~TypeActionBuff() = default;

    void map_action(const std::shared_ptr<Action> &action) override;
    Hexagon<uint> map_current(const Hexagon<uint> &current) override;
    bool expire() const override;
    void tick() override;
    string name() const override;

private:
    MoveCat _cat;
    double _rate;
    string _name;
    uint _expire;
};

#endif //POKEMON_CORE_TYPEACTIONBUFF_H
