//
// Created by wzq on 2019/7/3.
//

#ifndef CUDADGT_UTIL_H
#define CUDADGT_UTIL_H

#include <cstdlib>
#include "my_gauss_integer.h"
my_gauss_integer quick_mode_power(my_gauss_integer a, int64_t b, my_gauss_integer c);


bool prime_decomposition(int64_t prime, int64_t * a, int64_t * b);


int64_t quick_mod_power(int64_t a, int64_t b, int64_t c);

//找-1模p的二次剩余
int64_t find_neg_1(int64_t p);
#endif //CUDADGT_UTIL_H
