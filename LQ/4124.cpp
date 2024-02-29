/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LQ
  * @File           : 4124.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 两种糖果分别有9个和16个，要全部分给7个小朋友，每个小朋友得到的糖果总数最少为2个最
  *                     多为5个，问有多少种不同的分法。糖果必须全部分完。
  * @Attention      : 只要有其中一个小朋友在两种方案中分到的糖果不完全相同，这两种方案就算作不同的方案。
  * @Date           : 2024/2/27 19:22
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 25;
const int MAXM = 10;
long long dp[MAXM][MAXN][MAXN];

long long solve(int i, int j, int k) {
    if (i == 0) {
        if (j == 0 && k == 0) return 1;
        else return 0;
    }
    if (j < 0 || k < 0) return 0;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    long long ans = 0;
    for (int x = 0; x <= 5; ++x) {
        for (int y = 0; y <= 5; ++y) {
            if (x + y <= 5 && x + y >= 2) {
                ans += solve(i - 1, j - x, k - y);
            }
        }
    }
    return dp[i][j][k] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cout << solve(7, 9, 16) << endl;
    return 0;
}
