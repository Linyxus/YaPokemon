//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_BATTLE_H
#define POKEMON_CORE_BATTLE_H

#include <pokemon/PokemonInstance.h>
#include <common.h>

enum BattleStatus {
    LeftWin,
    RightWin,
    Ongoing
};

enum PokemonTurn {
    LeftTurn,
    RightTurn
};

struct BattleRound {
    PokemonTurn turn;
    shared_ptr<Move> move;
    Actions actions;
    bool miss;
};

class Battle {
public:
    Battle(const shared_ptr<Pokemon>& left, const shared_ptr<Pokemon>& right);
    BattleRound proceed();
    BattleStatus check() const;
    PokemonTurn next_turn() const;
    PokemonTurn turn_at(llint i) const;
    shared_ptr<PokemonInstance> left() const;
    shared_ptr<PokemonInstance> right() const;
    llint turn_count() const;

    static int get_exp(int this_level, int that_level);
    int exp_gain() const;
private:
    shared_ptr<PokemonInstance> _left;
    shared_ptr<PokemonInstance> _right;
    llint _turn_count;
};

#endif //POKEMON_CORE_BATTLE_H
