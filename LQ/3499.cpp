/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LQ
  * @File           : 3499.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/3/24 22:16
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

bool check(int n, int mod);

int main() {
    int count = 0, n = 1;
    while (count != 2023) {
        if (check(n, 2) && check(n, 8) && check(n, 10) && check(n, 16)) {
            count++;
        }
        n++;
    }
    cout << n - 1 << endl;
    return 0;
}

bool check(int n, int mod) {
    int sum = 0, tmp = n;
    while (n) {
        sum += n % mod;
        n /= mod;
    }
    if (tmp % sum == 0) {
        return true;
    }
    return false;
}
