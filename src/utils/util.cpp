//
// Created by wzq on 2019/7/3.
//
#include "util.h"
#include "my_gauss_integer.h"
#include "operation.h"
#include "iostream"
my_gauss_integer quick_mode_power(my_gauss_integer a, int64_t b, my_gauss_integer c){
    a = a % c;
    my_gauss_integer ans(1,0);
    my_gauss_integer temp;
    while(b!=0){
        if(b&1){
            temp = a * ans;
            ans = temp % c;
        }
        b>>=1;
        temp = a * a;
        a = temp % c;
    }
    return ans;
}

int64_t quick_mod_power(int64_t a, int64_t b, int64_t c){
    int64_t res=1;
    a=mod(a,c);
    while(b>0)
    {
        if(b&1) res=mod_mul(a,res,c);
        b=b>>1;
        a=mod_mul(a,a,c);
    }
    return res;
}

int64_t find_neg_1(int64_t p){
    //必定能找到-1的二次剩余，所以循环外不做判断
    for(int64_t a=1; a<p; a++){
        int64_t b=quick_mod_power(a,(p-1)/4,p);
        if(mod_mul(b,b,p)==p-1) return b<=(p-1)/2 ? b:p-b;
    }
    return 0;
}

bool prime_decomposition(int64_t prime ,int64_t * a, int64_t * b){
    int64_t A(0),B(0),U(0),V(0),M(0);
    A = find_neg_1(prime);
    B = 1;
    int64_t temp(1);
    M = (temp * A * A + temp * B * B) / prime;
    while (M > 1){
        U = mod(A,M);
        V = mod(B,M);
        if(U * 2 > M){
            U -= M;
        }
        if(V * 2 > M){
            V -= M;
        }
        int64_t ta = A;
        A = (temp * U * A + temp * V * B) / M;
        B = (temp * U * ta - temp * V * B) / M;
        M = (temp * U * U + temp * V * V) / M;
    }
    *a = A;
    *b = B;
    return true;
}