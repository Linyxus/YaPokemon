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
    PokemonZamazenta,
    /* 风速狗 */
    PokemonArcanine,
    /* 卡比兽 */
    PokemonSnorlax,
    /* 铝钢龙 */
    PokemonDuraludon,
    /* 双斧战龙 */
    PokemonHaxorus,
    /* 钢铠鸦 */
    PokemonCorviknight
};

const int PokemonNum = 9;

inline PokemonId rand_pokemon() {
    return static_cast<PokemonId>(randint(0, PokemonNum));
}

#endif //POKEMON_CORE_DEF_H
