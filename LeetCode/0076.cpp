/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LeetCode
  * @File           : 0076.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2025/3/30 22:23
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <bits/stdc++.h>

using namespace std;

class Solution1 {
	bool is_covered(int cnt_s[], int cnt_t[]) {
		for (int i = 'A'; i <= 'Z'; i++) {
			if (cnt_s[i] < cnt_t[i]) {
				return false;
			}
		}
		for (int i = 'a'; i <= 'z'; i++) {
			if (cnt_s[i] < cnt_t[i]) {
				return false;
			}
		}
		return true;
	}

public:
	string minWindow(string s, string t) {
		int m = s.length();
		int ans_left = -1, ans_right = m;
		int cnt_s[128]{}; // s 子串字母的出现次数
		int cnt_t[128]{}; // t 中字母的出现次数
		for (char c : t) {
			cnt_t[c]++;
		}

		int left = 0;
		for (int right = 0; right < m; right++) { // 移动子串右端点
			cnt_s[s[right]]++; // 右端点字母移入子串
			while (is_covered(cnt_s, cnt_t)) { // 涵盖
				if (right - left < ans_right - ans_left) { // 找到更短的子串
					ans_left = left; // 记录此时的左右端点
					ans_right = right;
				}
				cnt_s[s[left]]--; // 左端点字母移出子串
				left++;
			}
		}
		return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
	}
};

class Solution2 {
public:
	string minWindow(string s, string t) {
		int m = s.length();
		int ans_left = -1, ans_right = m;
		int cnt[128]{};
		int less = 0;
		for (char c : t) {
			if (cnt[c] == 0) {
				less++; // 有 less 种字母的出现次数 < t 中的字母出现次数
			}
			cnt[c]++;
		}

		int left = 0;
		for (int right = 0; right < m; right++) { // 移动子串右端点
			char c = s[right]; // 右端点字母
			cnt[c]--; // 右端点字母移入子串
			if (cnt[c] == 0) {
				// 原来窗口内 c 的出现次数比 t 的少，现在一样多
				less--;
			}
			while (less == 0) { // 涵盖：所有字母的出现次数都是 >=
				if (right - left < ans_right - ans_left) { // 找到更短的子串
					ans_left = left; // 记录此时的左右端点
					ans_right = right;
				}
				char x = s[left]; // 左端点字母
				if (cnt[x] == 0) {
					// x 移出窗口之前，检查出现次数，
					// 如果窗口内 x 的出现次数和 t 一样，
					// 那么 x 移出窗口后，窗口内 x 的出现次数比 t 的少
					less++;
				}
				cnt[x]++; // 左端点字母移出子串
				left++;
			}
		}
		return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
	}
};

int main() {
	string s = "ADOBECODEBANC", t = "ABC";
	Solution1 solution1;
	cout << solution1.minWindow(s, t) << endl;
	Solution2 solution2;
	cout << solution2.minWindow(s, t) << endl;
    return 0;
}
