/**
 * @BelongsProject: 04
 * @Author: yuan wang
 * @CreateTime: 2023-08-16  10:00
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

#define N 30
int pascal[N + 1][N + 1];

/**
 * @description: 杨辉三角
 * @author: yuan wang
 * @date: 2023/08/16 10:00
 * @param: null
 * @return: null
 */
int main() {
    int n;
    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;
    for (int i = 2; i < 31; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
        }
    }
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                cout << pascal[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
