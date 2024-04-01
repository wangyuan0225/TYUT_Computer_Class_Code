/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LQ
  * @File           : 3527.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/3/27 22:08
  * @Version        : 1.0 运行超时，需要一定的数学公式推导简化式子，仍然是一个遗留问题。
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

int mul(int a);

int main() {
    int n, sum = 0;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        sum += mul(a);
    }
    int i = 1;
    while (true) {
        if (sum % mul(i) != 0) {
            break;
        }
        i++;
    }
    cout << i - 1 << endl;
    return 0;
}

int mul(int a) {
    int mul = 1;
    while (a) {
        mul *= a;
        a--;
    }
    return mul;
}
