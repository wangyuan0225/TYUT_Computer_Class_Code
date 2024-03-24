/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 01
  * @File           : iterative.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 使用迭代法对给定的非线性方程进行求解
  * @Attention      : None
  * @Date           : 2024/3/14 10:47
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fi(double x);

int main() {
    double x = 1.25;
    while (abs(x - fi(x))> 0.000005) {
        x = fi(x);
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << fi(x) << endl;
    return 0;
}

double fi(double x) {
    return pow(x - 2 * x * x + 4, 0.25);
}
