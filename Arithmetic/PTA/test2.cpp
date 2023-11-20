#include <iostream>
#include <vector>

using namespace std;

const int INFTY = 1e9;

int findMinWeight(int n, int k, int Y, int *p, int *w, int *x, int **r) {
    if (Y == 0) {
        return 0;
    }
    if (k < 0) {
        return INFTY;
    }

    if (r[k][Y] != -1) { // 如果此子问题已解决，直接返回结果
        return r[k][Y];
    }

    int minWeight = INFTY;
    int minIdx = 0;
    for (int i = 0; i <= Y / p[k]; i++) {
        int weight = i * w[k] + findMinWeight(n, k - 1, Y - i * p[k], p, w, x, r);
        if (weight < minWeight) {
            minWeight = weight;
            minIdx = i;
        }
    }

    x[k] = minIdx; // 存储当前硬币的最优数量
    r[k][Y] = minWeight; // 存储当前最小总重量
    return minWeight;
}

int main() {
    int n, Y;
    cin >> n >> Y;
    int *p = new int[n];
    int *w = new int[n];
    int *x = new int[n]();
    int **r = new int*[n];

    for (int i = 0; i < n; ++i) {
        r[i] = new int[Y + 1];
        fill_n(r[i], Y + 1, -1);
    }

    findMinWeight(n, n - 1, Y, p, w, x, r);

    // 回溯过程
    int remainingY = Y;
    for (int i = n - 1; i >= 0; --i) {
        int coinCount = 0;
        while (remainingY > 0 && i > 0 && r[i][remainingY] < r[i-1][remainingY]) {
            coinCount++;
            remainingY -= p[i];
        }
        if (i == 0) { // 第一种硬币特殊处理
            coinCount = remainingY / p[0];
        }
        cout << coinCount << " ";
    }
    cout << endl;

    cout << r[n - 1][Y] << endl; // 输出最小总重量

    delete[] x;
    delete[] p;
    delete[] w;
    for (int i = 0; i < n; ++i) {
        delete[] r[i];
    }
    delete[] r;
    return 0;
}
