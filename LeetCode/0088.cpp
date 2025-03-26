/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : CompilationPrinciple
  * @File           : 0088.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2025/3/17 22:50
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int a = 0;
		int i = 0;
		for (; i < n && a < m + i; a++) {
			if (nums2[i] < nums1[a]) {
				for (int j = m + i; j > a; j--) {
					nums1[j] = nums1[j - 1];
				}
				nums1[a] = nums2[i];
				i++;
			}
		}
		if (i < n) {
			for (int j = a; j < m + n && i < n; j++) {
				nums1[j] = nums2[i];
				i++;
			}
		}
	}
};

int main() {
	vector<int> nums1 = {0, 1, 2, 8, 0, 0};
	vector<int> nums2 = {0, 2};
	Solution solution;
	solution.merge(nums1, 4, nums2, 2);
	for (int i = 0; i < nums1.size(); i++) {
		cout << nums1[i] << " ";
	}
	return 0;
}
