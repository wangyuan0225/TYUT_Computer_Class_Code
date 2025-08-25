/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Shopee
  * @File           : 03.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2025/4/2 20:11
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <bits/stdc++.h>

using namespace std;

int minCostClimbingStairs(int* cost, int costLen) {
	// write code here
	vector<int> dp(costLen + 1, 0);
	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i < costLen + 1; i++) {
		dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
	}

	return dp[costLen];
}

int main() {
	int cost[] = {2, 5, 20};
	cout << minCostClimbingStairs(cost, 3);
    return 0;
}
