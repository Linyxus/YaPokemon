//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_DEATHBUFF_H
#define YAPOKEMON_DEATHBUFF_H

#include <buff/Buff.h>
#include <pokemon/Hexagon.h>

class DeathBuff : public Buff {
public:
    explicit DeathBuff(int limit);

    void map_action(const std::shared_ptr<Action> &action) override;
    Hexagon<llint> map_current(const Hexagon<llint> &current) override;
    string name() const override;
    bool expire() const override;
    void tick() override;
    shared_ptr<Buff> clone() const override {
        return make_shared<DeathBuff>(*this);
    }
private:
    int _limit;
};


#endif //YAPOKEMON_DEATHBUFF_H
