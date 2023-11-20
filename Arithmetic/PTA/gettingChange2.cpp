/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : PTA
  * @File           : gettingChange2.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 找零钱问题（二）：
  *                     设一硬币系统有n种面值，第i种硬币的面值和重量分别为pi和wi，硬币面值的单位为元，
  *                     且有p1<p2<...<pn和p1=1，现需要给别人找Y∈Z+元钱，试确定一找零钱方案，使得所
  *                     找的硬币的总重量最轻。
  * @Attention      : 要求使用如下动态规划思想：
  *                     https://wy0225.oss-cn-beijing.aliyuncs.com/202311202248725.png
  * @Date           : 2023-11-19  19:26
  * @Version        : 2.0
  ****************************************************************************************
  */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, Y;
    cin >> n >> Y;
    vector<int> p(n), w(n), dp(Y + 1, INT_MAX), coinCount(n, 0), coinUsed(Y + 1, -1);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = p[i]; j <= Y; ++j) {
            if (dp[j - p[i]] != INT_MAX && dp[j - p[i]] + w[i] < dp[j]) {
                dp[j] = dp[j - p[i]] + w[i];
                coinUsed[j] = i;
            }
        }
    }

    if (dp[Y] == INT_MAX) {
        cout << "No solution";
    } else {
        int y = Y;
        while (y > 0) {
            coinCount[coinUsed[y]]++;
            y -= p[coinUsed[y]];
        }
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) {
                cout << coinCount[i];
                break;
            }
            cout << coinCount[i] << " ";
        }
        cout << endl << dp[Y];
    }

    return 0;
}
