/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 04
  * @File           : power.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/3/21 10:46
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double a[4][4] = {
            0, 0, 0, 0,
            0, 2, 3, 5,
            0, 10, 3, 4,
            0, 3, 6, 1
    };

    double x[4] = {0, 1, 1, 1};
    double y[4], m;
    while(true) {
        double sum = 0;
        for (int i = 1; i < 4; ++i) {
            for (int j = 1; j < 4; ++j) {
                sum += a[i][j] * x[j];
            }
            y[i] = sum;
            sum = 0;
        }
        m = *max_element(y + 1, y + 3);

        double tmp[4];
        for (int i = 1; i < 4; ++i) {
            tmp[i] = x[i];
        }

        for (int i = 1; i < 4; ++i) {
            x[i] = y[i] / m;
        }

        //范数
        for (int i = 1; i < 4; ++i) {
            tmp[i] -= x[i];
            tmp[i] = abs(tmp[i]);
        }
        if (*max_element(tmp + 1, tmp + 4) < 0.0005) {
            break;
        }
    }

    cout << m << endl;
    for (int i = 1; i < 4; ++i) {
        cout << x[i]  << " ";
    }

    return 0;
}
