//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_INFERNO_H
#define YAPOKEMON_INFERNO_H

#include <move/SpAttackMove.h>

class Inferno : public SpAttackMove {
public:
    Inferno();
    ~Inferno() = default;

    string name() const override;
    Actions move(shared_ptr<PokemonInstance> self, shared_ptr<PokemonInstance> target) override;

    string desc() const override {
        return "在全场燃起炼狱般的大火，造成大量伤害。且能灼伤对手，降低特防。提升双方火焰技能伤害。";
    }
};


#endif //YAPOKEMON_INFERNO_H
