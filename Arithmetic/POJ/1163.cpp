/**
 * @BelongsProject: POJ
 * @Author: yuan wang
 * @CreateTime: 2023-08-21  16:47
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

#define MAX 101
int n;
int arr[MAX][MAX];

using namespace std;

int MaxSum(int i, int j) {
    if (i == n - 1) {
        return arr[i][j];
    } else {
        return max(MaxSum(i + 1, j), MaxSum(i + 1, j + 1)) + arr[i][j];
    }
}

/**
 * @description: 数字三角形
 * @author: yuan wang
 * @date: 2023/08/21 16:47
 * @param: null
 * @return: null
 */
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> arr[i][j];
        }
    }
    cout << MaxSum(0, 0) << endl;
    return 0;
}
