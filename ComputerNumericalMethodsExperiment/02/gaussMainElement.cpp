/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 02
  * @File           : gaussMainElement.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/3/19 22:35
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    double a[4][5][6] = {
            0, 0, 0, 0, 0, 0,
            0, 0.3e-15, 59.14, 3, 1, 59.17,
            0, 5.291, -6.130, -1, 2, 46.78,
            0, 11.2, 9, 5, 2, 1,
            0, 1, 2, 1, 1, 2
    };
    double l[5][4];
    int stand[5] = {0, 1, 2, 3, 4};

    for (int k = 1; k <= 3; ++k) {
        double max = numeric_limits<double>::lowest();
        int max_row = 0;
        int max_col = 0;
        for (int i = k; i <= 4; ++i) {
            for (int j = k; j <= 4; ++j) {
                if (abs(a[k - 1][i][j]) > max) {
                    max = abs(a[k - 1][i][j]);
                    max_row = i;
                    max_col = j;
                }
            }
        }

        for (int j = 1; j < 6; ++j) {
            swap(a[k - 1][k][j], a[k - 1][max_row][j]);
        }

        for (int i = 1; i < 5; ++i) {
            swap(a[k - 1][i][k], a[k - 1][i][max_col]);
        }

        swap(stand[k], stand[max_col]);

        for (int i = k + 1; i <= 4; ++i) {
            for (int j = k + 1; j <= 5; ++j) {
                l[i][k] = a[k - 1][i][k] / a[k - 1][k][k];
                a[k][i][j] = a[k - 1][i][j] - l[i][k] * a[k - 1][k][j];
            }
        }
    }

    double x[5];
    x[4] = a[3][4][5] / a[3][4][4];
    for (int k = 3; k >= 1; --k) {
        double sum = 0;
        for (int j = k + 1; j <= 4; ++j) {
            sum += a[k - 1][k][j] * x[j];
        }
        x[k] = (a[k - 1][k][5] - sum) / a[k - 1][k][k];
    }

    for (int i = 1; i <= 4; ++i) {
        cout << x[stand[i]] << endl;
    }

    return 0;
}
