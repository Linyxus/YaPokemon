//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_HEXBUFF_H
#define POKEMON_CORE_HEXBUFF_H

#include <buff/Buff.h>
#include <pokemon/Hexagon.h>

class HexBuff : public Buff {
public:
    HexBuff(AbilityAxis axis, uint value, uint expire, string name = {});
    ~HexBuff() = default;

    void map_action(const std::shared_ptr<Action> &action) override;
    Hexagon<uint> map_current(const Hexagon<uint> &current) override;
    string name() const override;
    bool expire() const override;
    void tick() override;

private:
    AbilityAxis _axis;
    uint _value;
    string _name;
    uint _expire;
};

#endif //POKEMON_CORE_HEXBUFF_H
