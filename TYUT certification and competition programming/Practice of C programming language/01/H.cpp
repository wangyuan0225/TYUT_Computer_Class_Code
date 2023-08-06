/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-16  22:14
 * @Description: TODO:C++二改
 * @Version: 2.0
 */

#include <iostream>

using namespace std;

/**
 * @description: 求奇数的乘积
 * @author: yuan wang
 * @date: 2023/07/16 22:14
 * @param: null
 * @return: null
 */
int main() {
    int n;
    while (cin >> n) {
        int *arr = new int[n];
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; ++i) {
            if (arr[i] % 2 == 1) {
                ans *= arr[i];
            }
        }
        cout << ans << endl;
        delete []arr;
    }
    return 0;
}
