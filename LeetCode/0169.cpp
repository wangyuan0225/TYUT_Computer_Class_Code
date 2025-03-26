/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LeetCode
  * @File           : 0169.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2025/3/20 15:01
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		while (true) {
			int candidate = nums[rand() % nums.size()];
			int count = 0;
			for (int num: nums)
				if (num == candidate)
					++count;
			if (count > nums.size() / 2)
				return candidate;
		}
		return -1;
	}
};

int main() {
	vector nums = {3, 2, 3};
	cout << Solution().majorityElement(nums) << endl;
	return 0;
}
