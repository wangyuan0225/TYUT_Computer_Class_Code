/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 03
  * @File           : gauss-seidel.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 使用高斯-赛德尔迭代法对给定方程组进行求解
  * @Attention      : None
  * @Date           : 2024/3/21 10:07
  * @Version        : 1.0
  *                   2.0 添加必要注释，优化代码架构，采用常量表示。
  ****************************************************************************************
  */

#include <iostream>
#include <algorithm>

using namespace std;

const int n = 3;

int main() {
    double a[n + 1][n + 1] = {
            0, 0, 0, 0,
            0, 50, 10, 1,
            0, 1, 20, -1,
            0, 1, -1, 20
    };

    double b[n + 1] = {0, 73, 38, 59};

    double x[n + 1] = {0, 2, 2, 2};
    double tmp[n + 1];

    while (true) {
        for (int i = 1; i < n + 1; ++i) {
            tmp[i] = x[i];
        }
        for (int i = 1; i < n + 1; ++i) {
            double sum = 0;
            for (int j = 1; j < i; ++j) {
                sum += a[i][j] * x[j];
            }
            for (int j = i + 1; j < n + 1; ++j) {
                sum += a[i][j] * x[j];
            }
            x[i] = 1 / a[i][i] * (b[i] - sum);
        }

        // 无穷范数进行误差限制
        for (int i = 1; i < n + 1; ++i) {
            tmp[i] -= x[i];
            tmp[i] = abs(tmp[i]);
        }
        if (*max_element(tmp + 1, tmp + n + 1) < 0.000005) {
            break;
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        cout << x[i] << endl;
    }
    return 0;
}
