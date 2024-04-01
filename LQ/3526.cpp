/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LQ
  * @File           : 3526.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/3/25 21:22
  * @Version        : 1.0 没有做出来，题解看得一知半解，等之后有时间再回头看这道题吧。
  *                     https://www.notion.so/wy0225/3526-9d583d3ab9fa4e9581577438763a83ab?pvs=4
  ****************************************************************************************
  */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        // 判断 n 处于第几层
        int res = m, sum = 1, n_col = 1;
        while (sum < n) {
            sum += res;
            res *= m;
            n_col++;
        }

        //计算差值
        int minus = sum - n;

        // 判断 k 处于第几层
        res = m, sum = 1;
        int k_col = 1;
        while (sum < k) {
            sum += res;
            res *= m;
            k_col++;
        }

        if (k_col == n_col) {
            cout << 1 << endl;
            continue;
        }

        int all = 1;
        res = 1;
        for (int i = k_col; i < n_col; ++i) {
            res *= m;
            all += res;
        }

        if (k_col - n_col > 1) {
            cout << all - minus << endl;
            continue;
        }

        cout << all - minus << endl;
    }
    return 0;
}
