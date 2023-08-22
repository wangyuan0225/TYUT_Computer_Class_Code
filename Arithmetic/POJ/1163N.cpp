/**
 * @BelongsProject: POJ
 * @Author: yuan wang
 * @CreateTime: 2023-08-22  15:11
 * @Description: 动态规划解法
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

#define MAX 101
int n;
int arr[MAX][MAX];
int maxSum[MAX][MAX];

int MaxSum(int i, int j) {
    if (maxSum[i][j] != -1) {
        return maxSum[i][j];
    }
    if (i == n) {
        maxSum[i][j] = arr[i][j];
    } else {
        int x = MaxSum(i + 1, j);
        int y = MaxSum(i + 1, j + 1);
        maxSum[i][j] = max(x, y) + arr[i][j];
    }
    return maxSum[i][j];
}

/**
 * @description: 数字三角形
 * @author: yuan wang
 * @date: 2023/08/22 15:11
 * @param: null
 * @return: null
 */
int main() {
    int i, j;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= i; ++j) {
            cin >> arr[i][j];
            maxSum[i][j] = -1;
        }
    }
    cout << MaxSum(1, 1) << endl;
    return 0;
}
