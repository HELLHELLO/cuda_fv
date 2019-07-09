#include <iostream>
#include "precompute.h"
int main() {
    int32_t prime = 257;
    int32_t depth = 16;
    dgt_context* dgtContext = nullptr;
    if(generate_dgt_context(prime,depth,&dgtContext)){
        std::cout<<dgtContext->get_depth()<<std::endl;
    }
    return 0;
}