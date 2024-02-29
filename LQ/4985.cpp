/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LQ
  * @File           : 4985.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 这天，一只蜗牛来到了二维坐标系的原点。在α轴上长有n根竹竿。它们平行于y轴，底部纵坐
  *                     标为0，横坐标分别为x1,x2,...,xn。竹竿的高度均为无限高，完度可忽略。蜗牛x想要
  *                     从原点走到第 n 个竹竿的底部也就是坐标(xn, 0)。它只能在 x 轴上或者竹竿上爬行，
  *                     在 x 轴上爬行速度为1单位每秒；由于受到引力影响，蜗牛在竹竿上向上和向下爬行的速
  *                     度分别为 0.7 单位每秒和 1.3 单位每秒。
  *                     为了快速到达目的地，它施展了魔法，在第 i 和 i+1 根竹竿之间建立了传送门（0 <
  *                     i < n），如果蜗牛位于第 i 根竹竿的高度为 αi 的位置（xi, αi），就可以瞬间到达
  *                     第 i+1 根竹竿的高度为 b(i+1) 的位置（x(i+1),b(i+1)），请计算蜗牛最少需要
  *                     多少秒才能到达目的地。
  * @Attention      : 输入共 1+n 行，第一行为一个正整数n;
  *                     第二行为 n 个正整数 x1, x2,...,xn;
  *                     后面 n－1 行，每行两个正整数 ai,b(i+1)。
  * @Date           : 2024/2/28 18:12
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

const int MAXN = 100010;
double dp[MAXN][2];
long long x[MAXN];
int a[MAXN], b[MAXN];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &x[i]);
    }
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i + 1]);
    }

    dp[1][0] = x[1];
    dp[1][1] = x[1] + a[1] / 0.7;

    //printf("%f %f", dp[1][0], dp[1][1]);

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = min(dp[i - 1][0] + x[i] - x[i - 1], dp[i - 1][1] + b[i] / 1.3);
        if (a[i] < b[i]) {
            dp[i][1] = min(dp[i - 1][0] + x[i] - x[i - 1] + a[i] / 0.7, dp[i - 1][1] + (b[i] - a[i]) / 1.3);
        } else {
            dp[i][1] = min(dp[i - 1][0] + x[i] - x[i - 1] + a[i] / 0.7, dp[i - 1][1] + (a[i] - b[i]) / 0.7);
        }
    }

    printf("%.2f", dp[n][0]);
    return 0;
}
