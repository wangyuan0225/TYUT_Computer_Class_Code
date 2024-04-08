/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LQ
  * @File           : 3500.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/4/8 20:45
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

int main() {
    long long sum = 0;
    long long mul = 1;
    for (int i = 1; i < 41; ++i) {
        mul *= i;
        mul %= 1000000000;
        sum += mul;
        sum %= 1000000000;
    }
    cout << sum << endl;
}
