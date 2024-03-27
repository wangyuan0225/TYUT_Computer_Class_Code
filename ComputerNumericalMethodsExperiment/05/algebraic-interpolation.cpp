/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 05
  * @File           : algebraic-interpolation.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/3/26 14:09
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

int main() {
    double x[7] = {0, 0.40, 0.55, 0.65, 0.80, 0.90, 1.05};
    double y[7] = {0, 0.41075, 0.57815, 0.69675, 0.88811, 1.02652, 1.25386};
    double quotient[6][6]; // 差商

    // 一阶差商
    for (int i = 1; i < 6; i++) {
        quotient[1][i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
    }

    // 二阶差商往上
    for (int i = 2; i < 6; ++i) {
        for (int j = i; j < 6; ++j) {
            quotient[i][j] = (quotient[i - 1][j] - quotient[i - 1][j - 1]) / (x[j + 1] - x[j - i + 1]);
        }
    }

    double newton[5];
    newton[1] = y[1] + quotient[1][1] * (0.596 - x[1]);

    double multiply = 1;

    for (int i = 2; i < 5; ++i) {
        for (int j = 1; j <= i; ++j) {
            multiply *= (0.596 - x[i]);
        }
        newton[i] = newton[i - 1] + quotient[i][i] * multiply;
    }

    cout << newton[4] << endl;

//    for (int i = 1; i < 6; ++i) {
//        for (int j = 1; j < 6; ++j) {
//            cout << quotient[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
