//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_DRAGONDART_H
#define YAPOKEMON_DRAGONDART_H

#include <move/AttackMove.h>

class DragonDart : public AttackMove {
public:
    DragonDart();
    ~DragonDart() = default;

    string name() const override;

    string desc() const override {
        return "射出龙族的箭矢，造成伤害";
    }
};


#endif //YAPOKEMON_DRAGONDART_H
