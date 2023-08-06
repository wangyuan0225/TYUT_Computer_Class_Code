/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-17  09:53
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

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
    char (*arr)[8] = new char[n][8]();
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    return 0;
}
