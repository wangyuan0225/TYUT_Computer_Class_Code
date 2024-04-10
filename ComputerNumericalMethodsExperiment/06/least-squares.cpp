/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 06
  * @File           : least-squares.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : ��С���˷���϶���ʽ
  * @Attention      : ����һ�����߽������
  * @Date           : 2024/3/28 10:04
  * @Version        : 1.0
  *                   2.0 �Ż�����ܹ������ó�����ʾ��
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

const int n = 8;

int main() {
    double x[n] = {0, 0, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double y[n] = {0, 1, 1.75, 1.96, 2.19, 2.44, 2.71, 3.00};

    // ���췽���飬����һ���������
    // 1. ��� x, y, x^2, x * y;
    double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;
    for (int i = 1; i < n; ++i) {
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }

    // 2. ������Է�����
    // {[n - 1, sum_x, sum_y], [sum_x, sum_x2, sum_xy]}
    sum_x2 = sum_x2 * (n - 1) / sum_x - sum_x;
    sum_xy = sum_xy * (n - 1) / sum_x - sum_y;

    double a1 = sum_xy / sum_x2;
    double a0 = (sum_y - sum_x * a1) / (n - 1);

    cout << "f(x) = " << a0 << " + " << a1 << "x" << endl;

    // 3. ��ƽ�����
    double square_error = 0;
    for (int i = 0; i < n; ++i) {
        double predicted_y = a0 + a1 * x[i];
        double error = predicted_y - y[i];
        square_error += error * error;
    }
    cout << "ƽ����" << square_error << endl;

    return 0;
}
