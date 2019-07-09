//
// Created by wzq on 2019/7/3.
//

#ifndef CUDADGT_MY_COMPLEX_H
#define CUDADGT_MY_COMPLEX_H


#include <cstdint>

class my_gauss_integer {
private:
    int64_t real;
    int64_t imag;

public:
    my_gauss_integer(){
        this->imag = 0;
        this->real = 0;
    }
    my_gauss_integer(int64_t real, int64_t imag){
        this->real = real;
        this->imag = imag;
    }
    int64_t get_real(){
        return real;
    }
    int64_t get_imag(){
        return imag;
    }
    void set_real(int64_t real){
        this->real = real;
    }
    void set_imag(int64_t imag){
        this->imag = imag;
    }

    //����ģ���㣬�ֱ�Ϊģһ����˹������ģһ������
    my_gauss_integer operator % (my_gauss_integer moduler);
    my_gauss_integer operator % (int64_t moduler);

    //���ؼӷ����㣬
    my_gauss_integer operator + (my_gauss_integer addend);
    my_gauss_integer operator + (int64_t addend);

    //���ؼ������㣬
    my_gauss_integer operator - (my_gauss_integer subtrahend);
    my_gauss_integer operator - (int64_t subtrahend);

    //���س������㣬������Ϊ�������
    my_gauss_integer operator / (my_gauss_integer divisor);
    my_gauss_integer operator / (int64_t divisor);

    //���س˷�����
    my_gauss_integer operator * (my_gauss_integer multiplier);
    my_gauss_integer operator * (int64_t multiplier);

    bool operator == (my_gauss_integer b);
    bool operator != (my_gauss_integer b);
    my_gauss_integer operator - ();
};


#endif //CUDADGT_MY_COMPLEX_H
