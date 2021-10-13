#ifndef COMMON_H
#define COMMON_H

#include <random>

// Common code, make global
extern std::random_device dev;
extern std::mt19937 engine;
extern std::uniform_int_distribution<int> random_w;
extern std::uniform_int_distribution<int> random_h;

#endif