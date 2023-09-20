#include <stdio.h>

typedef struct { //负数类型
    float realPart; //实部
    float imagePart; //虚部
}Complex;

void createComplex(Complex *c, float realPart, float imagePart); //创建复数
void addComplex(Complex *c1, Complex c2, Complex c3); //复数相加

int main() {
    Complex z1, z2, z3;
    createComplex(&z1, 8.0, 6.0);
    createComplex(&z2, 4.0, 3.0);
    addComplex(&z3, z1, z2);
    return 0;
}

void createComplex(Complex *c, float realPart, float imagePart) { //创建复数
    c->realPart = realPart;
    c->imagePart = imagePart;
}
void addComplex(Complex *c1, Complex c2, Complex c3) { //复数相加
    c1->realPart = c2.realPart + c3.realPart;
    c1->imagePart = c2.imagePart + c3.imagePart;
}