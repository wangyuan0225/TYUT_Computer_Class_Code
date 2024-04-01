/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 05
  * @File           : algebraic-interpolation.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 使用拉格朗日插值法或牛顿插值法求解：已知f(x)在6个点的函数值如下表所示，运用插值
  *                     方法，求f(0.596)的近似值。
  * @Attention      : None
  * @Date           : 2024/3/26 14:09
  * @Version        : 1.0
  *                   2.0 添加必要注释，优化代码架构，采用常量表示。
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

const int n = 6;
const double req = 0.596;

int main() {
    double x[n + 1] = {0, 0.40, 0.55, 0.65, 0.80, 0.90, 1.05};
    double y[n + 1] = {0, 0.41075, 0.57815, 0.69675, 0.88811, 1.02652, 1.25386};
    double quotient[n][n]; // 差商

    // 一阶差商
    for (int i = 1; i < n; i++) {
        quotient[1][i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
    }

    // 二阶差商往上
    for (int i = 2; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            quotient[i][j] = (quotient[i - 1][j] - quotient[i - 1][j - 1]) / (x[j + 1] - x[j - i + 1]);
        }
    }

    double newton[n - 1];
    newton[1] = y[1] + quotient[1][1] * (req - x[1]);

    double multiply = 1;

    for (int i = 2; i < n - 1; ++i) {
        for (int j = 1; j <= i; ++j) {
            multiply *= (req - x[i]);
        }
        newton[i] = newton[i - 1] + quotient[i][i] * multiply;
    }

    cout << newton[n - 2] << endl;

    return 0;
}
