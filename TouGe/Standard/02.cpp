/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Standard
  * @File           : 02.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 小明正在利用股票的波动程度来研究股票。小明拿到了一只股票每天收盘时的价格，他想知道
  *                     ，这只股票连续几天的最大波动值是多少，即在这几天中某天收盘价格与前一天收盘价格之
  *                     差的绝对值最大是多少。
  * @Attention      : None
  * @Date           : 2024/6/28 9:41
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
    int max = 0;
    for (int i = 1; i < n; ++i) {
        int temp = a[i] - a[i - 1];
        if (temp < 0) {
            temp = -temp;
        }
        if (temp > max) {
            max = temp;
        }
    }
    cout << max << endl;
    return 0;
}
