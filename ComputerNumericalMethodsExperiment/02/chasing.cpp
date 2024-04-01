/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 02
  * @File           : chasing.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 利用追赶法求解给定的线性方程组
  * @Attention      : None
  * @Date           : 2024/3/21 22:25
  * @Version        : 1.0
  *                   2.0 添加必要注释
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // LU 分解
    double l[n + 1][n + 1], u[n + 1][n + 1];
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            l[i][j] = 0;
            u[i][j] = 0;
        }
    }
    l[1][1] = 2;
    u[1][2] = 1 / l[1][1];
    for (int i = 2; i <= n; ++i) {
        l[i][i - 1] = 1;
        l[i][i] = 2 - u[i - 1][i];
        u[i][i + 1] = 1 / l[i][i];
    }

    // 追
    double y[n + 1], x[n + 1];
    y[1] = -7 / l[1][1];
    for (int i = 2; i <= n; ++i) {
        y[i] = (-5 - l[i][i - 1] * y[i - 1]) / l[i][i];
    }

    // 赶
    x[n] = y[n];
    for (int i = n - 1; i > 0; --i) {
        x[i] = y[i] - u[i][i + 1] * x[i + 1];
    }

    for (int i = 1; i <= n; ++i) {
        cout << x[i] << endl;
    }
    return 0;
}
