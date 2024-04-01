/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 01
  * @File           : newton.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 牛顿迭代法求解一次方程
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
    double x = 1.25;
    int sum = 0;
    while (abs(x - newtonFx(x)) > 0.000005) {
        x = newtonFx(x);
        sum++;
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << newtonFx(x) << endl;
    return 0;
}

double fx(double x) {
    return pow(x, 4) + 2 * pow(x, 2) - x - 4;
}

double dFx(double x) {
    return 4 * pow(x, 3) + 4 * x - 1;
}

double newtonFx(double x) {
    return x - fx(x) / dFx(x);
}
