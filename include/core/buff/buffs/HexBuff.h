//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_HEXBUFF_H
#define POKEMON_CORE_HEXBUFF_H

#include <buff/Buff.h>
#include <pokemon/Hexagon.h>

class HexBuff : public Buff {
public:
    HexBuff(AbilityAxis axis, llint value, llint expire, string name = {});
    ~HexBuff() = default;

    void map_action(const std::shared_ptr<Action> &action) override;
    Hexagon<llint> map_current(const Hexagon<llint> &current) override;
    string name() const override;
    bool expire() const override;
    void tick() override;

    shared_ptr<Buff> clone() const override {
        return make_shared<HexBuff>(*this);
    }

private:
    AbilityAxis _axis;
    llint _value;
    string _name;
    llint _expire;
};

#endif //POKEMON_CORE_HEXBUFF_H
