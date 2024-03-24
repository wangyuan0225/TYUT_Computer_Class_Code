/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : ComputerNumericalMethodsExperiment
  * @File           : dichotomy.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 使用二分法对给定的非线性方程进行求解
  * @Attention      : None
  * @Date           : 2024/3/14 10:03
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fx(double x);

int main() {
    double left = 1, right = 1.5, x = 1;
    while (abs((left + right) / 2.0 - x) > 0.000005) {
        x = (left + right) / 2.0;
        if (fx(x) * fx(left) < 0) {
            right = x;
        }
        if (fx(x) * fx(right) < 0) {
            left = x;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << (left + right) / 2.0 << endl;
    return 0;
}

double fx(double x) {
    return pow(x, 4) + 2 * pow(x, 2) - x - 4;
}
