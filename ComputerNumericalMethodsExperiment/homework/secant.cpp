/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 01
  * @File           : secant.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/3/16 17:10
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fx(double x);

int main() {
    double x[3] = {2, 1.8};
    while (true) {
        x[2] = x[1] - (x[1] - x[0]) * fx(x[1]) / (fx(x[1]) - fx(x[0]));
        if (abs(x[2] - x[1]) < 0.00005) {
            cout << setiosflags(ios::fixed) << setprecision(6) << x[2] << endl;
            break;
        } else {
            x[0] = x[1];
            x[1] = x[2];
        }
        cout << setiosflags(ios::fixed) << setprecision(6) << x[2] << endl;
    }

    return 0;
}

double fx(double x) {
    return pow(x, 3) - 3 * x - 1;
}