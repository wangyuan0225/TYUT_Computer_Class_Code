/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 02
  * @File           : gauss.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/3/19 21:29
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

int main() {
    double a[3][4][5] = {
            0, 0, 0, 0, 0,
            0, 3, -4, 1, 11,
            0, 15, -14, 3, 47,
            0, 21, -40, 15, 97
    };
    double l[4][3];

    for (int k = 1; k <= 2; ++k) {
        for (int i = k + 1; i <= 3; ++i) {
            for (int j = k + 1; j <= 4; ++j) {
                l[i][k] = a[k - 1][i][k] / a[k - 1][k][k];
                a[k][i][j] = a[k - 1][i][j] - l[i][k] * a[k - 1][k][j];
            }
        }
    }
    double x[4];
    x[3] = a[2][3][4] / a[2][3][3];
    for (int k = 2; k >= 1; --k) {
        double sum = 0;
        for (int j = k + 1; j <= 3; ++j) {
            sum += a[k - 1][k][j] * x[j];
        }
        x[k] = (a[k - 1][k][4] - sum) / a[k - 1][k][k];
    }

    for (int i = 1; i <= 3; ++i) {
        cout << x[i] << endl;
    }

    return 0;
}
