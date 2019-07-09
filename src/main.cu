#include <iostream>
#include "precompute.h"
#include "cuda_runtime.h"
#include "cuda_runtime_api.h"

int main() {
    int32_t depth = 16;
    int32_t primes[30];
    dgt_context* dgtContext[30];
    for(int i=0; i < 30; i++){
        primes[i] = 257;
    }
    for(int i=0; i < 30; i++){
        if(!generate_dgt_context(primes[i],depth,&dgtContext[i])){
            std::cout<<"fail to generate dgt context for the"<<i<<"-th prime"<<std::endl;
        }
    }




    return 0;
}