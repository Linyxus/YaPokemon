//
// Created by Yichen Xu on 2020/9/1.
//

#include <battle/Battle.h>
#include <move/Move.h>

llint gcd(llint x, llint y) {
    if (!y) return x;
    return gcd(y, x % y);
}

Battle::Battle(const shared_ptr<Pokemon> &left, const shared_ptr<Pokemon> &right) {
    _turn_count = 1;
    _left = instance_of(left);
    _right = instance_of(right);
}

shared_ptr<PokemonInstance> Battle::left() const {
    return _left;
}

shared_ptr<PokemonInstance> Battle::right() const {
    return _right;
}

PokemonTurn Battle::turn_at(llint i) const {
    llint l = _left->current().speed;
    llint r = _right->current().speed;
    if (l == 0) l = 10;
    if (r == 0) r = 10;
    swap(l, r);
    llint current = 0;
    llint step = gcd(l, r);
    llint j = 0;
    while (j < i) {
        if ((current % l) == 0) {
            j += 1;
        }
        if (j == i) {
            return LeftTurn;
        }
        if ((current % r) == 0) {
            j += 1;
        }
        if (j == i) {
            return RightTurn;
        }
        current += step;
    }
    return LeftTurn;
}

PokemonTurn Battle::next_turn() const {
    return turn_at(_turn_count);
}

BattleStatus Battle::check() const {
    if (_right->current().hp == 0) {
        return LeftWin;
    }
    if (_left->current().hp == 0) {
        return RightWin;
    }
    return Ongoing;
}

shared_ptr<Move> get_move(const shared_ptr<PokemonInstance> &instance) {
    auto moves = instance->pokemon()->temp()->moves();
    auto i = weighted_sample(instance->pokemon()->temp()->move_weights());
    return moves[i];
}

BattleRound Battle::proceed() {
    if (check() != Ongoing) return {};
    auto turn = next_turn();

    Actions actions;
    shared_ptr<Move> move = nullptr;
    llint speed = turn == RightTurn ? _left->current().speed : _right->current().speed;
    double miss_rate = speed2miss(speed);
    bool miss = sample_miss(miss_rate);
    if (miss) {
        _turn_count += 1;
        return {
            turn, move, actions, miss
        };
    }
    if (turn == LeftTurn) {
        move = get_move(_left);
        actions = move->move(_left, _right);
        for (const auto &action : actions) {
            if (action->target() == ActSelf) {
                _left->accept_action(action);
            } else {
                _right->accept_action(action);
            }
        }
    } else {
        move = get_move(_right);
        actions = move->move(_right, _left);
        for (const auto &action : actions) {
            if (action->target() == ActSelf) {
                _right->accept_action(action);
            } else {
                _left->accept_action(action);
            }
        }
    }

    _turn_count += 1;
    return {
            turn, move, actions, miss
    };
}

llint Battle::turn_count() const {
    return _turn_count;
}

int Battle::get_exp(int this_level, int that_level) {
    if (that_level >= this_level) {
        return 40 + (that_level - this_level) * 10;
    }
    int exp = (4 - (this_level - that_level)) * 10;
    return exp < 10 ? 10 : exp;
}

int Battle::exp_gain() const {
    return get_exp(_left->pokemon()->level(), _right->pokemon()->level());
}
