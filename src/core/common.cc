//
// Created by Yichen Xu on 2020/9/1.
//

#include <common.h>
#include <cassert>

double power2rate(uint power) {
    return power * power / 14400.0;
}

double defense2rate(uint d) {
    return -1 / (1 + d / 50.0) + 1;
}

double speed2miss(uint d) {
    return -1 / (1 + d / 100.0) + 1;
}

uint ensure_range(int x, uint low, uint high) {
    x = x > low ? x : low;
    x = x < high ? x : high;

    return x;
}

int randint(int low, int high) {
    assert(low < high);
    int x = std::rand();
    int w = high - low;
    x = x % w + low;
    return x;
}

bool sample_miss(double miss_rate) {
    uint threshold = 10000 * miss_rate;
    int x = randint(0, 10000 + 1);
    return x < threshold;
}
