/**
 * @BelongsProject: 02
 * @Author: yuan wang
 * @CreateTime: 2023-07-17  19:35
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cmath>

using namespace std;

/**
 * @description: 水仙花数
 * @author: yuan wang
 * @date: 2023/07/17 19:35
 * @param: null
 * @return: null
 */
int main() {
    int m, n;
    while (cin >> m) {
        bool exist = false;
        cin >> n;
        for (int i = m; i <= n; ++i) {
            if (i == pow(i / 100, 3) + pow(i % 100 / 10, 3) + pow(i % 10, 3)) {
                cout << i << " ";
                exist = true;
            }
        }
        if (!exist) {
            cout << "no";
        }
        cout << endl;
    }
    return 0;
}
