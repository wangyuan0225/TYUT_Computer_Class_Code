/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : soldiersInFormation.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 在一个划分成网格的操场上，n个士兵散乱地站在网格点上。网格点用整数坐标(x,y)表示。
  *                     士兵们可以沿网格边往上、下、左、右移动一步，但在同一时刻任一网格点上只能有一名士
  *                     兵。按照军官的命令，士兵们要整齐地列成一个水平队列，即排列成(x,y),(x+1,y),…,
  *                     (x+n-1,y)。如何选择x和y的值才能使士兵们以最少的总移动步数排成一行。编程计算使
  *                     所有士兵排成一行需要的最少移动步数。
  * @Attention      : 输入格式:
  *                     第1行是士兵数n，1≤n≤10000。接下来n行是士兵的初始位置，每行有2个整数x和y，
  *                     -10000≤x，y≤10000。
  *                   输出格式:
  *                     一个数据，即士兵排成一行需要的最少移动步数。
  * @Date           : 2023-12-01  19:04
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *x = new int[n];
    int *y = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x, x + n);
    sort(y, y + n);
    for (int i = 1; i <= n; ++i) {
        x[i] -= i;
    }
    sort(x, x + n);
    int rex, rey;
    if (n % 2 == 0) {
        rex = (x[n / 2 - 1] + x[n / 2]) / 2;
        rey = (y[n / 2 - 1] + y[n / 2]) / 2;
    } else {
        rex = x[n / 2];
        rey = y[n / 2];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(x[i] - rex) + abs(y[i] - rey);
    }
    cout << sum << endl;
    return 0;
}