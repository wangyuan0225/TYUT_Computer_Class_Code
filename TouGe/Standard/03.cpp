/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Standard
  * @File           : 03.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 给定一个整数数列，数列中连续相同的最长整数序列算成一段，问数列中共有多少段？
  * @Attention      : None
  * @Date           : 2024/6/28 9:43
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
