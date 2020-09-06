//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_DEF_H
#define POKEMON_CORE_DEF_H

#include <common.h>

enum PokemonId {
    /* 伊布 */
    PokemonEevee,
    /* 皮卡丘 */
    PokemonPikachu,
    /* 苍响 (宝可梦剑神兽) */
    PokemonZacian,
    /* 多龙 (多龙巴鲁托) */
    PokemonDragapult,
    /* 臧然玛特 (宝可梦盾神兽) */
    PokemonZamazenta
};

const int PokemonNum = 5;

inline PokemonId rand_pokemon() {
    return static_cast<PokemonId>(randint(0, PokemonNum));
}

#endif //POKEMON_CORE_DEF_H
