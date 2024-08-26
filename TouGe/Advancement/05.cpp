/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Advancement
  * @File           : 05.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 每年冬天，小明所在学校就会组织起滑冰活动，学校体育组准备了许多冰鞋，可是人太多了，
  *                     每天下午收工后，常常一双冰鞋都不剩。
                      每天早上，租鞋窗口都会排起长龙，假设有还鞋的 m 个人，有需要租鞋的 n 个人。现在存在
                        一个问题，这些人有多少种排法，可以避免出现体育组没有冰鞋可租的尴尬场面。
                      两个同样需求的人，比如都是租鞋或都是还鞋，交换位置是同一种排法。
                      聪明的你可以帮帮体育组的人员吗？
  * @Attention      : 输入格式
                        输入包含两个整数 m,n，含义如题目描述所示。
                        整数之间以空格间隔。
                      输出格式
                        针对输入，打印出一个整数，表示队伍的排法的方案数。
  * @Date           : 2024/6/28 15:33
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    // 创建一个二维动态规划表格
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

    // 初始状态
    dp[0][0] = 1;

    // 填充动态规划表格
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j > 0 && i >= j) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    // 输出结果
    cout << dp[m][n] << endl;

    return 0;
}
