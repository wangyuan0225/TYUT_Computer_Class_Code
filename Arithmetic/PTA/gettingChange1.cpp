/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : PTA
  * @File           : gettingChange1.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 找零钱问题（一）：
  *                     设一硬币系统有n种面值，第i种硬币的面值和重量分别为pi和wi，硬币面值的单位为元，
  *                     且有p1<p2<...<pn和p1=1，现需要给别人找Y∈Z+元钱，试确定一找零钱方案，使得所
  *                     找的硬币的总重量最轻。
  * @Attention      : 要求使用如下动态规划思想：
  *                     https://wy0225.oss-cn-beijing.aliyuncs.com/202311191114075.png
  * @Date           : 2023-11-19  11:12
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INFTY = 1e9;

/**
 * 寻找找钱硬币总重量最小方案
 * @param n 硬币种数
 * @param k 选取前 k 种硬币
 * @param Y 所需找的钱数
 * @param p 每种硬币面值
 * @param w 每种硬币重量
 * @param x 当前硬币数量
 * @param optimal 最优硬币数量
 * @return 最小的总重量
 */
int findMinWeight(int n, int k, int Y, int *p, int *w, int *x, int *optimal) {
    if (k == 0) {
        optimal[0] = Y;
        return Y * w[0];
    } else {
        int min = INFTY;
        int *tempX = new int[n];
        for (int count = 0; count <= Y / p[k]; count++) {
            x[k] = count;
            int tmp = x[k] * w[k] + findMinWeight(n, k - 1, Y - x[k] * p[k], p, w, x, tempX);
            if (tmp < min) {
                min = tmp;
                // 保存最优解
                memcpy(optimal, x, sizeof(int) * (k + 1));
                memcpy(optimal + k + 1, tempX + k + 1, sizeof(int) * (n - k - 1));
            }
        }
        return min;
    }
}

int main() {
    int n, Y;
    cin >> n >> Y;
    int *p = new int[n];
    int *w = new int[n];
    int *x = new int[n]();
    int *optimal = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    int min = findMinWeight(n, n - 1, Y, p, w, x, optimal);

    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            cout << optimal[i];
            break;
        }
        cout << optimal[i] << " ";
    }
    cout << endl << min;

    delete[] x;
    delete[] p;
    delete[] w;
    delete[] optimal;
    return 0;
}