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
};


#endif //YAPOKEMON_QUICKGUARD_H
