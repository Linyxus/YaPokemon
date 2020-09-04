//
// Created by Yichen Xu on 2020/8/28.
//

#ifndef POKEMON_CORE_COMMON_H
#define POKEMON_CORE_COMMON_H

#include <ctime>
#include <cstdlib>

typedef unsigned int uint;

uint ensure_range(int x, uint low, uint high = -1);

double power2rate(uint power);

int randint(int low, int high);

double defense2rate(uint d);

double speed2miss(uint d);

double speed2critical(uint d);

bool sample_miss(double miss_rate);

#endif //POKEMON_CORE_COMMON_H
