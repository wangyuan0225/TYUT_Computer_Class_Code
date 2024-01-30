/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : LQ
  * @File           : test.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024-01-25  22:58
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <bit>
#include <algorithm>

using namespace std;

int a[30];

bool check(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}

int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int U = 1 << n;
    for (int S = 0; S < U; S++)
        if (popcount(static_cast<unsigned int>(S)) == k) {
            int sum = 0;
            for (int i = 0; i < n; i++)
                if (S & (1 << i))
                    sum += a[i];
            if (check(sum))
                ans++;
        }
    next_permutation();
    cout << ans;
    return 0;
}