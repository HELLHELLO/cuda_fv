//
// Created by wzq on 2019/7/3.
//

#include "dgt_context.h"
#include "util.h"
#include "vector"
#include "operation.h"
#include "iostream"

#define DEBUG_DGT

bool dgt_context::check() {
    return setted;
}

bool dgt_context::find_g() {
    int64_t a(0),b(0);
    prime_decomposition(this->prime,&a,&b);
    f0.set_real(a);
    f0.set_imag(b);
    f1.set_real(a);
    f1.set_imag(-b);
#ifdef DEBUG_DGT
    std::cout<<a<<","<<b<<std::endl;
#endif

    //查找两个复数域上的原根
    int64_t fp(prime-1); //p的欧拉函数值
    std::vector<int64_t> factor_list;
    int64_t q = 2;
    if (mod(fp,4*depth) != 0){
        return false;
    }

    //找出p-1的所有因子
    while(q * q < fp){
        if(mod(fp, q) == 0){
            factor_list.push_back(q);
            while(mod(fp, q) == 0){
                fp = fp / q;
            }
        }
        q++;
    }
    my_gauss_integer gf0(1,0),gf1(1,0);
    fp = prime - 1;
    for(int64_t i=1; i < prime; i++){
        gf0.set_real(i);
        bool found = true;
        std::vector<int64_t>::iterator it;
        for (it = factor_list.begin(); it != factor_list.end() ; it ++) {
            if(quick_mode_power(gf0,fp/(*it),f0) == my_gauss_integer(1,0)){
                found = false;
                break;
            }
        }
        if(found){
            my_gauss_integer gfi0 = quick_mode_power(gf0,fp/(4*depth),f0);
            if(quick_mode_power(gfi0,depth,f0) == my_gauss_integer(0,1)){
                gf0.set_real(gfi0.get_real());
                gf0.set_imag(gfi0.get_imag());
                break;
            }
        }
    }
    for(int64_t i=1; i < prime; i++){
        gf1.set_real(i);
        bool found = true;
        std::vector<int64_t>::iterator it;
        for (it = factor_list.begin(); it != factor_list.end() ; it ++) {
            if(quick_mode_power(gf1,fp/(*it),f1) == my_gauss_integer(1,0)){
                found = false;
                break;
            }
        }
        if(found){
            my_gauss_integer gfi1 = quick_mode_power(gf1,fp/(4*depth),f1);
            if(quick_mode_power(gfi1,depth,f1) == my_gauss_integer(0,1)){
                gf1.set_real(gfi1.get_real());
                gf1.set_imag(gfi1.get_imag());
                break;
            }
        }
    }
    my_gauss_integer t0 = quick_mode_power(f1,prime-2,f0);
    my_gauss_integer t1 = (my_gauss_integer(1,0) - t0 * f1) / f0;
    my_gauss_integer M(prime,0);
    gi = (gf0 * t0 * f1 + gf1 * t1 * f0)%M;
    g = quick_mode_power(gi,4,M);
#ifdef DEBUG_DGT
    std::cout<<"gi:"<<gi.get_real()<<","<<gi.get_imag()<<std::endl;
    std::cout<<"g:"<<g.get_real()<<","<<g.get_imag()<<std::endl;
#endif
    gi_list = new my_gauss_integer[depth];
    g_list = new my_gauss_integer[depth];
    gi_list[0] = my_gauss_integer(1,0);
    g_list[0] = my_gauss_integer(1,0);
    for (int64_t i= 1; i < depth; i++) {
        g_list[i] = g_list[i-1] * g;
        gi_list[i] = gi_list[i-1] * gi;
    }
    setted = true;

    return true;
}
