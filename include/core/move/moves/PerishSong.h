//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_PERISHSONG_H
#define YAPOKEMON_PERISHSONG_H

#include <move/BufMove.h>

class PerishSong : public BufMove {
public:
    PerishSong();

    string name() const override;

    string desc() const override {
        return "吟唱灭亡之歌。对手在四回合后陷入濒死状态。";
    }

    MoveCat move_cat() const override {
        return MCSacred;
    }
};


#endif //YAPOKEMON_PERISHSONG_H
