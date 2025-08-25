/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LeetCode
  * @File           : 01.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2025/4/2 19:25
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
	int solve(string nums) {
		// write code here
		int len = nums.size();
		vector<int> dp(len + 1, 0);
		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= len; i++) {
			if (nums[i - 1] != '0') {
				dp[i] += dp[i - 1];
			}

			int num = stoi(nums.substr(i - 2, 2));
			if (num >= 10 && num <= 26) {
				dp[i] += dp[i - 2];
			}
		}

		return dp[len];

	}
};



int main() {

    return 0;
}
