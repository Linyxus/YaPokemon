//
// Created by Yichen Xu on 2020/9/1.
//

#ifndef POKEMON_CORE_TYPES_MOVE_H
#define POKEMON_CORE_TYPES_MOVE_H
#include <string>

enum MoveCat {
    MCNormal,
    MCWater,
    MCFire,
    MCGrass,
    MCStorm,
    MCIce,
    MCDragon,
    MCThunder,
    MCSacred
};

inline std::string show_move_cat(MoveCat cat) {
    switch(cat) {
        case MCNormal:
            return "一般";
        case MCWater:
            return "水";
        case MCFire:
            return "火";
        case MCGrass:
            return "草";
        case MCStorm:
            return "风";
        case MCIce:
            return "冰";
        case MCDragon:
            return "龙";
        case MCThunder:
            return "雷电";
        case MCSacred:
            return "神圣";
    }
}

#endif //POKEMON_CORE_MOVE_H
