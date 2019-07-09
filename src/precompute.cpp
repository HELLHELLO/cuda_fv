//
// Created by wzq on 2019/7/3.
//
#include "precompute.h"

bool test_gauss_prime(int32_t prime){
    return mod(prime, 4) == 3;
}

bool generate_dgt_context(int32_t prime, int32_t depth, dgt_context** context){
    //����û�����Լ�⣬�Ժ��ٿ��ǣ�Ŀǰ����֪�����ڸ�˹��÷ɭ������ô��ԭ����������ֻʵ�ֶԷǸ�˹���������������ɡ�
    if (test_gauss_prime(prime)){
        *context = nullptr;
        return false;
    }
    auto* temp = new dgt_context(prime,depth);
    if(!temp->find_g()){
        return false;
    }
    if(temp->check()){
        *context = temp;
        return true;
    }
    return false;
}
