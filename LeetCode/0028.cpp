/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LeetCode
  * @File           : 0028.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2025/3/26 14:03
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void getNext(int* next, const string& s) {
		int j = -1;
		next[0] = j;
		for(int i = 1; i < s.size(); i++) { // 注意i从1开始
			while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
				j = next[j]; // 向前回退
			}
			if (s[i] == s[j + 1]) { // 找到相同的前后缀
				j++;
			}
			next[i] = j; // 将j（前缀的长度）赋给next[i]
		}
	}
	int strStr(string haystack, string needle) {
		if (needle.size() == 0) {
			return 0;
		}
		vector<int> next(needle.size());
		getNext(&next[0], needle);
		int j = -1; // // 因为next数组里记录的起始位置为-1
		for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
			while(j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
				j = next[j]; // j 寻找之前匹配的位置
			}
			if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动
				j++; // i的增加在for循环里
			}
			if (j == (needle.size() - 1) ) { // 文本串s里出现了模式串t
				return (i - needle.size() + 1);
			}
		}
		return -1;
	}
};

int main() {
	string haystack = "aabaabaafa";
	string needle = "aabaaf";
	Solution s;
	cout << s.strStr(haystack, needle) << endl;
    return 0;
}
