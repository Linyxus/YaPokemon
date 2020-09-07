//
// Created by Yichen Xu on 2020/9/5.
//

#ifndef YAPOKEMON_QUICKGUARD_H
#define YAPOKEMON_QUICKGUARD_H

#include <move/BufMove.h>

class QuickGuard : public BufMove {
public:
    QuickGuard();
    ~QuickGuard() = default;

    string name() const override;

    string desc() const override {
        return "摆出防御的姿态，提升防御";
    }

    MoveCat move_cat() const override {
        return MCNormal;
    }
};


#endif //YAPOKEMON_QUICKGUARD_H
