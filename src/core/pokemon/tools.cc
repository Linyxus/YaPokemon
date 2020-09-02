//
// Created by Yichen Xu on 2020/9/2.
//

#include <pokemon/tools.h>

ostream &operator<<(ostream &os, const shared_ptr<Pokemon>& pokemon) {
    auto name = pokemon->temp()->name();
    auto level = pokemon->level();

    os << name << ' ' << level << "级";

    return os;
}

ostream &operator<<(ostream &os, const shared_ptr<PokemonInstance>& instance) {
    auto hp_max = instance->pokemon()->max().hp;
    auto hp_now = instance->current().hp;
    os << instance->pokemon()->name() << ' ' << instance->pokemon()->level() << ' ' << hp_now << '/' << hp_max;
    return os;
}
