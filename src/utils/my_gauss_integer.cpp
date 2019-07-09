//
// Created by wzq on 2019/7/3.
//

#include "my_gauss_integer.h"
#include "iostream"
#include "operation.h"

my_gauss_integer my_gauss_integer::operator%(int64_t moduler) {
    my_gauss_integer result;
    result.set_real(static_cast<int64_t>(mod(this->real,moduler)));
    result.set_imag(static_cast<int64_t>(mod(this->imag,moduler)));
    return result;
}

my_gauss_integer my_gauss_integer::operator%(my_gauss_integer moduler) {
    my_gauss_integer result;
    int64_t a = this->real;
    int64_t b = this->imag;
    int64_t c = moduler.get_real();
    int64_t d = moduler.get_imag();
    int64_t nTempReal = a * c + b * d;
    int64_t modLen = c * c + d * d;
    int64_t nRealDown = mod(nTempReal, modLen);
    int64_t nRealUp = modLen - nRealDown;
    int64_t nTempImag = b * c - a * d;
    int64_t nImagDown = mod(nTempImag, modLen);
    int64_t nImagUp = modLen - nImagDown;
    int64_t nReal(0),nImag(0);

    if (nRealDown < nRealUp){
        nReal = (nTempReal - nRealDown) / modLen;
    }else{
        nReal = (nTempReal + nRealUp) / modLen;
    }

    if (nImagDown < nImagUp){
        nImag = (nTempImag - nImagDown) / modLen;
    }else{
        nImag = (nTempImag + nImagUp) / modLen;
    }

    int64_t resultReal = a - (nReal * c - nImag * d);
    int64_t resultImag = b - (nImag * c + nReal * d);
    result.set_imag(static_cast<int64_t>(resultImag));
    result.set_real(static_cast<int64_t>(resultReal));
    return result;
}

my_gauss_integer my_gauss_integer::operator+(int64_t addend) {
    my_gauss_integer result((this->real)+addend,this->imag);
    return result;
}

my_gauss_integer my_gauss_integer::operator+(my_gauss_integer addend) {
    my_gauss_integer result((this->real)+addend.get_real(),(this->imag)+addend.get_imag());
    return result;
}

my_gauss_integer my_gauss_integer::operator-(int64_t subtrahend) {
    my_gauss_integer result((this->real)-subtrahend,this->imag);
    return result;
}

my_gauss_integer my_gauss_integer::operator-(my_gauss_integer subtrahend) {
    my_gauss_integer result((this->real)-subtrahend.get_real(),(this->imag)-subtrahend.get_imag());
    return result;
}

my_gauss_integer my_gauss_integer::operator/(int64_t divisor) {
    my_gauss_integer result((this->real)/divisor,(this->imag)/divisor);
    return result;
}

my_gauss_integer my_gauss_integer::operator/(my_gauss_integer divisor) {
    my_gauss_integer result;
    int64_t a = this->real;
    int64_t b = this->imag;
    int64_t c = divisor.get_real();
    int64_t d = divisor.get_imag();
    int64_t nTempReal = a * c + b * d;
    int64_t modLen = c * c + d * d;
    int64_t nRealDown = mod(nTempReal, modLen);
    int64_t nRealUp = modLen - nRealDown;
    int64_t nTempImag = b * c - a * d;
    int64_t nImagDown = mod(nTempImag, modLen);
    int64_t nImagUp = modLen - nImagDown;
    int64_t nReal(0),nImag(0);

    if (nRealDown < nRealUp){
        nReal = (nTempReal - nRealDown) / modLen;
    }else{
        nReal = (nTempReal + nRealUp) / modLen;
    }

    if (nImagDown < nImagUp){
        nImag = (nTempImag - nImagDown) / modLen;
    }else{
        nImag = (nTempImag + nImagUp) / modLen;
    }

    result.set_imag(static_cast<int64_t>(nImag));
    result.set_real(static_cast<int64_t>(nReal));
    return result;
}

my_gauss_integer my_gauss_integer::operator*(int64_t multiplier) {
    my_gauss_integer result((this->real)*multiplier,(this->imag)*multiplier);
    return result;
}

my_gauss_integer my_gauss_integer::operator*(my_gauss_integer multiplier) {
    my_gauss_integer result;
    int64_t a = this->real;
    int64_t b = this->imag;
    int64_t c = multiplier.get_real();
    int64_t d = multiplier.get_imag();
    result.set_real(a*c - b*d);
    result.set_imag(a*d + c*b);
    return result;
}

bool my_gauss_integer::operator==(my_gauss_integer b) {
    return this->real == b.get_real() && this->imag == b.get_imag();
}

my_gauss_integer my_gauss_integer::operator-() {
    my_gauss_integer result(-(this->real),-(this->imag));
    return result;
}

bool my_gauss_integer::operator!= (my_gauss_integer b){
    return this->real != b.get_real() || this->imag != b.get_imag();
}
