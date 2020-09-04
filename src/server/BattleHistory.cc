//
// Created by Yichen Xu on 2020/9/4.
//

#include <include/server/BattleHistory.h>
#include <utility>

BattleHistory::BattleHistory(Battle battle) : _battle(std::move(battle)), _history {}, _result {Ongoing} {}

const Battle &BattleHistory::battle() const {
    return _battle;
}

const QList<BattleStep> &BattleHistory::history() const {
    return _history;
}

BattleStatus BattleHistory::result() const {
    return _result;
}

BattleRound BattleHistory::proceed() {
    assert(_battle.check() == Ongoing);
    auto res = _battle.proceed();

    BattleStep checkpoint;
    checkpoint.round = res;
    checkpoint.left = _battle.left()->clone();
    checkpoint.right = _battle.right()->clone();
    _history << checkpoint;

    return res;
}

void BattleHistory::complete() {
    auto status = Ongoing;
    while (status == Ongoing) {
        proceed();
        status = _battle.check();
    }
    _result = status;
}

BattleResult BattleHistory::run_battle(const shared_ptr<Pokemon> &left, const shared_ptr<Pokemon> &right) {
    auto sess = Battle(left, right);
    auto wrapper = BattleHistory(sess);
    wrapper.complete();
    return { wrapper.result(), wrapper.history() };
}

