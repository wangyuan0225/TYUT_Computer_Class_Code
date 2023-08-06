/**
 * @BelongsProject: 03
 * @Author: yuan wang
 * @CreateTime: 2023-08-06  09:01
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

/**
 * @description: 数据的交换输出
 * @author: yuan wang
 * @date: 2023/08/06 09:01
 * @param: null
 * @return: null
 */
int main() {
    int n;
    while (cin >> n && n != 0) {
        int tmp = 0;
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] <= arr[tmp]) {
                tmp = i;
            }
        }
        int t = arr[0];
        arr[0] = arr[tmp];
        arr[tmp] = t;
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        delete[] arr;
    }
    return 0;
}
