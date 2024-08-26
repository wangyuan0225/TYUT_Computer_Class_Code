/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Advancement
  * @File           : 04.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 小明数学刀法。他要斩断数列，他的刀锋为 k。对于任意一个整数数列，我们可以在数中间放
  *                     一个符号 + 或 -，这样就可以构成一个表达式。如果构成的表达式的结果能被 k 整除，
  *                     则视为能斩断这个数列。请你帮小明判断他能否斩断给定的序列。
  * @Attention      : 输入格式
                        第一行两个整数 n 和 k，n 表示数列中整数的个数，k 表示小明的刀锋的数值
                        第二行 n 个整数，表示输入数列 {a_n}。数据之间有一个空格隔开。
                      输出格式
                        若数列能被 k 整除则输出 Divisible，否则输出 Not divisible
  * @Date           : 2024/6/28 15:29
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i] %= k;  // 取模，简化问题
        if (arr[i] < 0) arr[i] += k;  // 保证非负
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(k, false));
    dp[0][0] = true;  // 初始状态

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (dp[i][j]) {
                dp[i + 1][(j + arr[i]) % k] = true;
                dp[i + 1][(j - arr[i] + k) % k] = true;
            }
        }
    }

    if (dp[n][0]) {
        cout << "Divisible" << endl;
    } else {
        cout << "Not divisible" << endl;
    }

    return 0;
}