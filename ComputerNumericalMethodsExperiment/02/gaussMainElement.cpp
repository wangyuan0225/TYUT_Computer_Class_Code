/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 02
  * @File           : gaussMainElement.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 利用 Gauss 消元法求解给定的线性方程组，并采用完全主元素法进行优化
  * @Attention      : None
  * @Date           : 2024/3/19 22:35
  * @Version        : 1.0
  *                   2.0 优化代码架构，采用常量表示，优化数组 a 为 2 维数组。
  ****************************************************************************************
  */

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int n = 4;

int main() {
    double a[n + 1][n + 2] = {
            0, 0, 0, 0, 0, 0,
            0, 0.3e-15, 59.14, 3, 1, 59.17,
            0, 5.291, -6.130, -1, 2, 46.78,
            0, 11.2, 9, 5, 2, 1,
            0, 1, 2, 1, 1, 2
    };
    double l[n + 1][n];

    // 初始化角标标记函数
    int stand[n + 1];
    for (int i = 1; i <= n; ++i) {
        stand[i] = i;
    }

    // 消元过程，采用完全主元素进行优化
    for (int k = 1; k <= n - 1; ++k) {

        // 找到最大元素所在的行列
        double max = numeric_limits<double>::lowest();
        int max_row = 0;
        int max_col = 0;
        for (int i = k; i <= n; ++i) {
            for (int j = k; j <= n; ++j) {
                if (abs(a[i][j]) > max) {
                    max = abs(a[i][j]);
                    max_row = i;
                    max_col = j;
                }
            }
        }

        //交换行列
        for (int j = 1; j <= n + 1; ++j) {
            swap(a[k][j], a[max_row][j]);
        }
        for (int i = 1; i <= n; ++i) {
            swap(a[i][k], a[i][max_col]);
        }

        // 交换角标标记函数
        swap(stand[k], stand[max_col]);

        // 实际的消元过程
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
        cout << x[stand[i]] << endl;
    }

    return 0;
}
