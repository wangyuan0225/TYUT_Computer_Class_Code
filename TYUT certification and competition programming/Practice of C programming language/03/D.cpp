/**
 * @BelongsProject: 03
 * @Author: yuan wang
 * @CreateTime: 2023-08-06  10:11
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

int count(int n);

/**
 * @description: 母牛的故事
 * @author: yuan wang
 * @date: 2023/08/06 10:11
 * @param: null
 * @return: null
 */
int main() {
    int n;
    while (cin >> n && n != 0) {
        cout << count(n) << endl;
    }
    return 0;
}

int count(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (n == 3) {
        return 3;
    } else if (n == 4) {
        return 4;
    } else if (n == 5) {
        return 6;
    } else if (n > 5) {
        return 2 * count(n - 3) + count(n - 5) + count(n - 4);
    }
    return 0;
}