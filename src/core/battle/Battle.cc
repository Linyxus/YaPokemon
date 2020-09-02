//
// Created by Yichen Xu on 2020/9/1.
//

#include <battle/Battle.h>
#include <move/Move.h>

uint gcd(uint x, uint y) {
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

PokemonTurn Battle::turn_at(uint i) const {
    uint l = _left->current().speed;
    uint r = _right->current().speed;
    swap(l, r);
    uint current = 0;
    uint step = gcd(l, r);
    uint j = 0;
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
    auto len = moves.size();
    auto i = randint(0, len);
    return moves[i];
}

BattleRound Battle::proceed() {
    if (check() != Ongoing) return {};
    auto turn = next_turn();

    Actions actions;
    shared_ptr<Move> move = nullptr;
    uint speed = turn == RightTurn ? _left->current().speed : _right->current().speed;
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

uint Battle::turn_count() const {
    return _turn_count;
}
