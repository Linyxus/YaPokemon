//
// Created by Yichen Xu on 2020/9/4.
//

#ifndef YAPOKEMON_BATTLEHISTORY_H
#define YAPOKEMON_BATTLEHISTORY_H

#include <battle/Battle.h>
#include <QList>

struct BattleStep {
    BattleRound round;
    shared_ptr<PokemonInstance> left;
    shared_ptr<PokemonInstance> right;
};

using BattleResult = std::pair<BattleStatus, QList<BattleStep>>;

class BattleHistory {
public:
    explicit BattleHistory(Battle battle);
    BattleRound proceed();
    const Battle &battle() const;
    void complete();
    const QList<BattleStep> &history() const;
    BattleStatus result() const;
    static BattleResult run_battle(const shared_ptr<Pokemon> &left, const shared_ptr<Pokemon> &right);

private:
    Battle _battle;
    QList<BattleStep> _history;
    BattleStatus _result;
};

#endif //YAPOKEMON_BATTLEHISTORY_H
