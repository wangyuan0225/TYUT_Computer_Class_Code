/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : 0-1backpack.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 给定n(n<=100)种物品和一个背包。物品i的重量是wi(wi<=100)，价值为vi(vi<=100)，
  *                     背包的容量为C(C<=1000)。应如何选择装入背包中的物品，使得装入背包中物品的总价值
  *                     最大? 在选择装入背包的物品时，对每种物品i只有两个选择：装入或不装入。不能将物品
  *                     i装入多次，也不能只装入部分物品i。
  * @Attention      : 输入格式:
  *                     共有n+1行输入：第一行为n值和c值，表示n件物品和背包容量c；接下来的n行，每行有两
  *                     个数据，分别表示第i(1≤i≤n)件物品的重量和价值。
  *                   输出格式:
  *                     输出装入背包中物品的最大总价值。
  * @Date           : 2023-12-01  23:07
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> w(n + 1);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
            }
        }
    }
    cout << dp[n][c] << endl;
    return 0;
}