/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Standard
  * @File           : 01.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 小明带着 N 元钱去买酱油。酱油 10 块钱一瓶，商家进行促销，每买 3 瓶送 1 瓶，或者
  *                     每买 5 瓶送 2 瓶。请问小明最多可以得到多少瓶酱油。
  * @Attention      : None
  * @Date           : 2024/6/28 9:31
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    while (n / 50 != 0) {
        sum += 7;
        n -= 50;
    }
    while (n / 30 != 0) {
        sum += 4;
        n -= 30;
    }
    sum += n / 10;
    cout << sum << endl;
    return 0;
}
