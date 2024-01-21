/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : PTA
  * @File           : travelingSalesman.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 某售货员要到若干城市去推销商品，已知各城市之间的路程(或旅费)。他要选定一条从驻地出
  *                     发，经过每个城市一遍，最后回到驻地的路线，使总的路程（或总旅费）最小。
  * @Attention      : 输入格式:
  *                     第一行为城市数n下面n行n列给出一个完全有向图，如 i 行 j 列表示第 i 个城市到第
  *                     j 个城市的距离。
  *                   输出格式:
  *                     一个数字，表示最短路程长度。
  * @Date           : 2023-12-07  10:29
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

constexpr int MAX = 10;
int n;
int dist[MAX][MAX];
int minCost = 1e9;
bool visited[MAX];

void TSP(int const pos, int const cost, int const count) {
    if (count == n && dist[pos][0]) {
        minCost = min(minCost, cost + dist[pos][0]);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[pos][i]) {
            visited[i] = true;
            TSP(i, cost + dist[pos][i], count + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    visited[0] = true;
    TSP(0, 0, 1);
    cout << minCost << endl;
    return 0;
}

