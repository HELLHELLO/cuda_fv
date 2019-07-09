//
// Created by wzq on 2019/7/3.
//

#ifndef CUDADGT_OPERATION_H
#define CUDADGT_OPERATION_H
#include "cstdint"

int64_t mod(int64_t a, int64_t b);

//return a*b % c
int64_t mod_mul(int64_t a,int64_t b, int64_t c);
#endif //CUDADGT_OPERATION_H
