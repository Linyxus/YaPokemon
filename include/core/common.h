//
// Created by Yichen Xu on 2020/8/28.
//

#ifndef POKEMON_CORE_COMMON_H
#define POKEMON_CORE_COMMON_H

#include <ctime>
#include <cstdlib>
#include <vector>

typedef long long llint;

llint ensure_range(int x, llint low, llint high = -1);

double power2rate(llint power);

int randint(int low, int high);

double defense2rate(llint d);

double speed2miss(llint d);

double speed2critical(llint d);

bool sample_miss(double miss_rate);

int weighted_sample(std::vector<int> p);

#endif //POKEMON_CORE_COMMON_H
