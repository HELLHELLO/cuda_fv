//
// Created by wzq on 2019/7/3.
//

#ifndef CUDADGT_PRECOMPUTE_H
#define CUDADGT_PRECOMPUTE_H

#include "my_gauss_integer.h"
#include "cstdint"
#include "operation.h"
#include "dgt_context.h"
bool test_gauss_prime(int32_t prime);

bool generate_dgt_context(int32_t prime, int32_t depth, dgt_context** context);
#endif //CUDADGT_PRECOMPUTE_H
