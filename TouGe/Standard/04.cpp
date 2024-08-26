/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Standard
  * @File           : 04.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/28 9:45
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

int main() {
    int T, S;
    cin >> T;
    if (T <= 3500) {
        S = T;
    }
    else if (T <= 4955) {
        S = (T - 3500) / 0.97 + 3500;
    }
    else if (T <= 7655) {
        S = (T - 4955) / 0.9 + 5000;
    }
    else if (T <= 11255) {
        S = (T - 7655) / 0.8 + 8000;
    }
    else if (T <= 30755) {
        S = (T - 11255) / 0.75 + 12500;
    }
    else if (T <= 44755) {
        S = (T - 30755) / 0.7 + 38500;
    }
    else if (T <= 61005) {
        S = (T - 44755) / 0.65 + 58500;
    }
    else {
        S = (T - 61005) / 0.55 + 83500;
    }
    cout << S << endl;
    return 0;
}
