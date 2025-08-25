/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LeetCode
  * @File           : 02.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2025/4/2 19:56
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
	string LCS(string str1, string str2) {
		// write code here
		int s1len = str1.length(), s2len = str2.length();
		vector<vector<int>> dp(s1len + 1, vector<int>(s2len + 1, 0));
		int res = 0;
		int end = 0;

		for (int i = 1; i < s1len + 1; i++) {
			for (int j = 1; j < s2len + 1; j++) {
				if (str1[i - 1] == str2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					if (dp[i][j] > res) {
						res = dp[i][j];
						end = i - 1;
					}
				} else {
					dp[i][j] = 0;
				}
			}
		}

		return str1.substr(end - res + 1, res);
	}
};


int main() {

    return 0;
}
