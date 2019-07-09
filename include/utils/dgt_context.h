//
// Created by wzq on 2019/7/3.
//

#ifndef CUDADGT_DGT_CONTEXT_H
#define CUDADGT_DGT_CONTEXT_H

#include "my_gauss_integer.h"

class dgt_context {
private:
    int32_t prime;
    //这个是DGT的深度，多项式的深度是他的两倍,p和n之间应该有某种限制关系
    int32_t depth;
    my_gauss_integer g;
    my_gauss_integer gi;
    my_gauss_integer* g_list;
    my_gauss_integer* gi_list;
    my_gauss_integer f0;
    my_gauss_integer f1;
    bool setted;
public:
    dgt_context(int32_t prime,int32_t depth):
    prime(prime), setted(false), depth(depth), g(0,0), gi(0,0), g_list(nullptr), gi_list(nullptr), f0(0,0), f1(0,0){
    }
    ~dgt_context(){
        if(setted){
            delete[] g_list;
            delete[] gi_list;
        }
    }

    bool check();
    bool find_g();
    int32_t get_prime(){
        return prime;
    }
    int32_t get_depth(){
        return depth;
    }

};


#endif //CUDADGT_DGT_CONTEXT_H
