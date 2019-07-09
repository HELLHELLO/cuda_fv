//
// Created by wzq on 2019/7/3.
//
#include "operation.h"
#include "cstdint"

// b应该大于0
int64_t mod(int64_t a, int64_t b){
    int64_t temp = a%b;
    if (temp < 0){
        temp += b;
    }
    return temp;
}

// b应该大于0
int64_t mod_mul(int64_t a,int64_t b, int64_t c){
    int64_t res=0;
    a=mod(a,c);
    while(b)
    {
        if(b&1){
            res=mod((res+a),c);
        }
        b>>=1;
        a=mod((a+a),c);
    }
    return res;
}

