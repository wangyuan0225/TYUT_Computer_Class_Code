/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 03
  * @File           : gauss-seidel.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/3/21 10:07
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double a[4][4] = {
            0, 0, 0, 0,
            0, 50, 10, 1,
            0, 1, 20, -1,
            0, 1, -1, 20
    };

    double b[4] = {0, 73, 38, 59};

    double x[4] = {0, 2, 2, 2};
    double tmp[4];

    while (true) {
        for (int i = 1; i < 4; ++i) {
            tmp[i] = x[i];
        }
        for (int i = 1; i < 4; ++i) {
            double sum = 0;
            for (int j = 1; j < i; ++j) {
                sum += a[i][j] * x[j];
            }
            for (int j = i + 1; j < 4; ++j) {
                sum += a[i][j] * x[j];
            }
            x[i] = 1 / a[i][i] * (b[i] - sum);
        }

        // 范数
        for (int i = 1; i < 4; ++i) {
            tmp[i] -= x[i];
            tmp[i] = abs(tmp[i]);
        }
        if (*max_element(tmp + 1, tmp + 4) < 0.000005) {
            break;
        }
    }
    for (int i = 1; i < 4; ++i) {
        cout << x[i] << endl;
    }
    return 0;
}
