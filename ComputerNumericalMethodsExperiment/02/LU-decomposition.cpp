/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 02
  * @File           : LU-decomposition.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/3/19 22:32
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

int main() {
    double a[7][8] = {
            0, 0, 0, 0, 0, 0, 0, 0,
            0, 28, 50, 77, -69, -84, -65, -349,
            0, 84, -100, -15, -31, -26, -5, -95,
            0, -25, 30, -86, -34, -4, 30, 357,
            0, -21, 7, -26, -86, -75, 88, 630,
            0, -85, 95, -47, 24, 12, -66, -114,
            0, -57, -85, 4, 50, -11, 54, 340
    };

    double u[7][7] = {0}, l[7][7] = {0};
    for (int j = 1; j < 7; ++j) {
        u[1][j] = a[1][j];
    }
    for (int i = 2; i < 7; ++i) {
        l[i][1] = a[i][1] / u[1][1];
    }

    for (int k = 2; k < 7; ++k) {
        for (int j = k; j < 7; ++j) {
            double sum = 0;
            for (int i = 1; i < k; ++i) {
                sum += l[k][i] * u[i][j];
            }
            u[k][j] = a[k][j] - sum;
        }
        for (int i = k + 1; i < 7; ++i) {
            double sum = 0;
            for (int j = 1; j < k; ++j) {
                sum += l[i][j] * u[j][k];
            }
            l[i][k] = (a[i][k] - sum) / u[k][k];
        }
    }

    for (int i = 1; i < 7; ++i) {
        for (int j = 1; j < 7; ++j) {
            cout << u[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i < 7; ++i) {
        for (int j = 1; j < 7; ++j) {
            cout << l[i][j] << " ";
        }
        cout << endl;
    }

    double y[7], x[7];
    y[1] = a[1][7];
    for (int k = 2; k < 7; ++k) {
        double sum = 0;
        for (int j = 1; j < k; ++j) {
            sum += l[k][j] * y[j];
        }
        y[k] = a[k][7] - sum;
    }

    x[6] = y[6] / u[6][6];
    for (int k = 5; k > 0; --k) {
        double sum = 0;
        for (int j = k + 1; j < 7; ++j) {
            sum += u[k][j] * x[j];
        }
        x[k] = (y[k] - sum) / u[k][k];
    }

    for (int i = 1; i < 7; ++i) {
        cout << x[i] << endl;
    }

    return 0;
}
