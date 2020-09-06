//
// Created by Yichen Xu on 2020/9/1.
//

#include <include/core/common.h>
#include <cassert>
#include <vector>

int weighted_sample(std::vector<int> p) {
    auto sum = 0;
    for (auto i : p) {
        sum += i;
    }
    auto i = randint(0, sum);
    int acc = 0;
    for (int j = 0; j < p.size(); j++) {
        acc += p[j];
        if (acc >= i) return j;
    }

    return 0;
}

double power2rate(llint power) {
    return power * power / 14400.0;
}

double defense2rate(llint d) {
    return -1 / (1 + d / 50.0) + 1;
}

double speed2miss(llint d) {
    return -1 / (1 + d / 200.0) + 1;
}

double speed2critical(llint d) {
    // TODO design speed -> critical rate function
    // pick up here!
    return 0;
}

llint ensure_range(int x, llint low, llint high) {
    x = x > low ? x : low;
    x = x < high ? x : high;

    return x;
}

int randint(int low, int high) {
    assert(low < high);
    int x = rand();
    int w = high - low;
    x = x % w + low;
    return x;
}

bool sample_miss(double miss_rate) {
    llint threshold = 10000 * miss_rate;
    int x = randint(0, 10000 + 1);
    return x < threshold;
}

