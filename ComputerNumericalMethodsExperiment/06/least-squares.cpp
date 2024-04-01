/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 06
  * @File           : least-squares.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 最小二乘法拟合多项式
  * @Attention      : 采用一次曲线进行拟合
  * @Date           : 2024/3/28 10:04
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

int main() {
    double x[8] = {0, 0, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double y[8] = {0, 1, 1.75, 1.96, 2.19, 2.44, 2.71, 3.00};

    // 构造方程组，采用一次曲线拟合
    // 1. 求和 x, y, x^2, x * y;
    double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;
    for (int i = 1; i < 8; ++i) {
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }

    // 2. 求解线性方程组
    // {[7, sum_x, sum_y], [sum_x, sum_x2, sum_xy]}
    sum_x2 = sum_x2 * 7 / sum_x - sum_x;
    sum_xy = sum_xy * 7 / sum_x - sum_y;

    double a1 = sum_xy / sum_x2;
    double a0 = (sum_y - sum_x * a1) / 7;

    cout << "f(x) = " << a0 << " + " << a1 << "x" << endl;

    // 3. 求平方误差
    double square_error = 0;
    for (int i = 0; i < 8; ++i) {
        double predicted_y = a0 + a1 * x[i];
        double error = predicted_y - y[i];
        square_error += error * error;
    }
    cout << "平方误差：" << square_error << endl;

    return 0;
}
