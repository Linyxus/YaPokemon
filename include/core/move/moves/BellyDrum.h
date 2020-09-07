//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_BELLYDRUM_H
#define YAPOKEMON_BELLYDRUM_H

#include <move/BufMove.h>

class BellyDrum : public BufMove {
public:
    BellyDrum();
    ~BellyDrum() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;
    string desc() const override {
        return "用力击打腹部来鼓舞斗志。消耗一半生命值，让攻击大幅提高。";
    }

    MoveCat move_cat() const override {
        return MCNormal;
    }
};


#endif //YAPOKEMON_BELLYDRUM_H
