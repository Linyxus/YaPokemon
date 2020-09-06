//
// Created by Yichen Xu on 2020/9/6.
//

#ifndef YAPOKEMON_PERISHSONG_H
#define YAPOKEMON_PERISHSONG_H

#include <move/BufMove.h>

class PerishSong : public BufMove {
public:
    PerishSong();

    string name() const override;
};


#endif //YAPOKEMON_PERISHSONG_H
