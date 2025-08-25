/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LeetCode
  * @File           : 0044.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2025/8/23 22:58
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m;
	cin >> n >> m;
	int sum = 0;
	vector<vector<int>> vec(n, vector<int>(m, 0)) ;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vec[i][j];
			sum += vec[i][j];
		}
	}

	int result = INT_MAX;
	int count = 0; // 统计遍历过的行
	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < m; j++) {
			count += vec[i][j];
			// 遍历到行末尾时候开始统计
			if (j == m - 1) result = min (result, abs(sum - count - count));

		}
	}

	count = 0; // 统计遍历过的列
	for (int j = 0; j < m; j++) {
		for (int i = 0 ; i < n; i++) {
			count += vec[i][j];
			// 遍历到列末尾的时候开始统计
			if (i == n - 1) result = min (result, abs(sum - count - count));
		}
	}
	cout << result << endl;
}