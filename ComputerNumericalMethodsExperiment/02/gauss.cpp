/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 02
  * @File           : gauss.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 利用 Gauss 消元法求解给定的线性方程组
  * @Attention      : None
  * @Date           : 2024/3/19 21:29
  * @Version        : 1.0
  *                   2.0 优化代码架构，采用常量表示，优化数组 a 为 2 维数组。
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

const int n = 3;

int main() {
    double a[n + 1][n + 2] = {
            0, 0, 0, 0, 0,
            0, 3, -4, 1, 11,
            0, 15, -14, 3, 47,
            0, 21, -40, 15, 97
    };
    double l[n + 1][n];

    // 消元过程
    for (int k = 1; k <= n - 1; ++k) {
        for (int i = k + 1; i <= n; ++i) {
            for (int j = k + 1; j <= n + 1; ++j) {
                l[i][k] = a[i][k] / a[k][k];
                a[i][j] = a[i][j] - l[i][k] * a[k][j];
            }
        }
    }

    // 回代过程
    double x[n + 1];
    x[n] = a[n][n + 1] / a[n][n];
    for (int k = n - 1; k >= 1; --k) {
        double sum = 0;
        for (int j = k + 1; j <= n; ++j) {
            sum += a[k][j] * x[j];
        }
        x[k] = (a[k][n + 1] - sum) / a[k][k];
    }

    for (int i = 1; i <= n; ++i) {
        cout << x[i] << endl;
    }

    return 0;
}
