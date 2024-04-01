/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : CPPExperiment
  * @File           : trueBackpackStory.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : The 0-1 knapsack problem is a classical dynamic programming problem.
  *                     This problem is often introduced with a story like this: A thief
  *                     sneaked into a museum where N precious antiques are arranged. Each
  *                     antique has a weight and a value, and the thief carries a backpack
  *                     with a weight limit W. Therefore, the goal of the thief is to choose
  *                     some antiques so that the total weight does not exceed W and the
  *                     total value is maximized. This story makes it sound like the thief
  *                     can easily and freely pick items, just like shopping in a supermarket.
  *                     But in reality, the thief is on edge and there is always a danger of
  *                     triggering an alarm as soon as he takes an item. So the thief wants
  *                     to take as few items as possible and run away immediately, but his
  *                     professional "ethics" do not allow him to leave the backpack empty.
  *                     Can you help him solve this dilemma?
  * @Attention      : Input format:
  *                     The first line contains 2 integers N and W, where 1<N≤100 indicates
  *                     the number of antiques, and 1<W≤2000 indicates the weight limit of
  *                     the backpack. The following N lines of data, each contain two positive
  *                     integers. The integers vi and wi on the i-th line (1≤i≤N) represent the
  *                     value and weight of the i-th antique, respectively. The values of vi
  *                     and wi do not exceed 2000.
  *                   Output format:
  *                     In one line, output two integer values, separated by a space. The first
  *                     integer represents the maximum total value that can be obtained by
  *                     filling the backpack, and the second integer indicates the minimum number
  *                     of antiques to be put into the backpack to achieve this maximum value.
  * @Date           : 2023-12-02  09:28
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> v(N + 1), w(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    vector<vector<int>> count(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            // If the weight of the current item is greater than the remaining capacity of the knapsack,
            if (j < w[i]) {
                dp[i][j] = dp[i - 1][j];
                count[i][j] = count[i - 1][j];
            } else {
                // Check if not taking the current item gives a higher value
                if (dp[i - 1][j] > dp[i - 1][j - w[i]] + v[i]) {
                    dp[i][j] = dp[i - 1][j];
                    count[i][j] = count[i - 1][j];
                }
                // Check if taking the current item gives a higher value
                else if (dp[i - 1][j] < dp[i - 1][j - w[i]] + v[i]) {
                    dp[i][j] = dp[i - 1][j - w[i]] + v[i];
                    count[i][j] = count[i - 1][j - w[i]] + 1;
                }
                // If the value is the same, choose the option with the minimum number of items
                else {
                    dp[i][j] = dp[i - 1][j];
                    count[i][j] = min(count[i - 1][j], count[i - 1][j - w[i]] + 1);
                }
            }
        }
    }

    cout << dp[N][W] << " " << count[N][W] << endl;

    return 0;
}