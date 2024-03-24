/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 01
  * @File           : newton.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : ×÷ÒµÌâ²âÊÔ
  * @Attention      : None
  * @Date           : 2024/3/14 13:40
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double newtonFx(double x);

int main() {
    double x = 11;
    int sum = 0;
    while (abs(x - newtonFx(x)) > 0.000005) {
        cout << setiosflags(ios::fixed) << setprecision(6) << newtonFx(x) << endl;
        x = newtonFx(x);
        sum++;
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << newtonFx(x) << endl;
    return 0;
}

double fx(double x) {
    return x * x - 115;
}

double dFx(double x) {
    return 2 * x;
}

double newtonFx(double x) {
    return x - fx(x) / dFx(x);
}
