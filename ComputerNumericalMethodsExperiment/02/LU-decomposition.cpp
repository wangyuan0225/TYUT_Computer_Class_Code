/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 02
  * @File           : LU-decomposition.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 利用 LU 分解法求解给定的线性方程组
  * @Attention      : None
  * @Date           : 2024/3/19 22:32
  * @Version        : 1.0
  *                   2.0 添加必要注释，优化代码架构，采用常量表示。
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

const int n = 6;

int main() {
    double a[n + 1][n + 2] = {
            0, 0, 0, 0, 0, 0, 0, 0,
            0, 28, 50, 77, -69, -84, -65, -349,
            0, 84, -100, -15, -31, -26, -5, -95,
            0, -25, 30, -86, -34, -4, 30, 357,
            0, -21, 7, -26, -86, -75, 88, 630,
            0, -85, 95, -47, 24, 12, -66, -114,
            0, -57, -85, 4, 50, -11, 54, 340
    };

    // LU 分解
    double u[n + 1][n + 1] = {0}, l[n + 1][n + 1] = {0};
    for (int j = 1; j < n + 1; ++j) {
        u[1][j] = a[1][j];
    }
    for (int i = 2; i < n + 1; ++i) {
        l[i][1] = a[i][1] / u[1][1];
    }

    for (int k = 2; k < n + 1; ++k) {
        for (int j = k; j < n + 1; ++j) {
            double sum = 0;
            for (int i = 1; i < k; ++i) {
                sum += l[k][i] * u[i][j];
            }
            u[k][j] = a[k][j] - sum;
        }
        for (int i = k + 1; i < n + 1; ++i) {
            double sum = 0;
            for (int j = 1; j < k; ++j) {
                sum += l[i][j] * u[j][k];
            }
            l[i][k] = (a[i][k] - sum) / u[k][k];
        }
    }

    // 输出 LU 矩阵
    cout << "U 矩阵：" << endl;
    for (int i = 1; i < n + 1; ++i) {
        l[i][i] = 1;
        for (int j = 1; j < n + 1; ++j) {
            cout << u[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "L 矩阵：" << endl;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cout << l[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // 求解 x 和 y
    double y[n + 1], x[n + 1];
    y[1] = a[1][n + 1];
    for (int k = 2; k < n + 1; ++k) {
        double sum = 0;
        for (int j = 1; j < k; ++j) {
            sum += l[k][j] * y[j];
        }
        y[k] = a[k][n + 1] - sum;
    }

    x[n] = y[n] / u[n][n];
    for (int k = n - 1; k > 0; --k) {
        double sum = 0;
        for (int j = k + 1; j < n + 1; ++j) {
            sum += u[k][j] * x[j];
        }
        x[k] = (y[k] - sum) / u[k][k];
    }

    cout << "求解结果：(";
    for (int i = 1; i < n; ++i) {
        cout << x[i] << ", ";
    }
    cout << x[n] << ")" << endl;

    return 0;
}
