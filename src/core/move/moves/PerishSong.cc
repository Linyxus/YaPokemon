//
// Created by Yichen Xu on 2020/9/6.
//

#include "include/core/move/moves/PerishSong.h"
#include <buff/buffs/DeathBuff.h>

PerishSong::PerishSong()
        : BufMove(
        make_shared<DeathBuff>(3),
        ActTarget) {}

string PerishSong::name() const {
    return "灭亡之歌";
}
