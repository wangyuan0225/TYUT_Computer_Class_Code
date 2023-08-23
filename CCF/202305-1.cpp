/**
 * @BelongsProject: CCF
 * @Author: yuan wang
 * @CreateTime: 2023-07-17  09:53
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cstring>

using namespace std;

/**
 * @description: 重复局面
 * @author: yuan wang
 * @date: 2023/07/17 09:53
 * @param: null
 * @return: null
 */
int main() {
    int n = 0;
    cin >> n;
    char (*arr)[9][9] = new char[n][9][9];
    int *count = new int[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 8; ++j) {
                cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        count[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            bool same = true;
            for (int k = 0; k < 8; ++k) {
                if (strcmp(arr[i][k], arr[j][k]) != 0) {
                    same = false;
                    break;
                }
            }
            if (same) {
                count[i] = count[j];
                count[i]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << count[i] << endl;
    }
    delete[] count;
    delete[] arr;
    return 0;
}
