//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_OUTRAGE_H
#define YAPOKEMON_OUTRAGE_H

#include <move/AttackMove.h>

class Outrage : public AttackMove {
public:
    Outrage();
    ~Outrage() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;

    string desc() const override {
        return "发狂地攻击对手。自己也会陷入狂躁状态，降低防御。";
    }
};


#endif //YAPOKEMON_OUTRAGE_H
