/**
 * @BelongsProject: Bailian
 * @Author: yuan wang
 * @CreateTime: 2023-08-10  10:24
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;
int N;

/**
 * 计算 n 阶楼梯走法
 * @param n
 * @return
 */
int stairs(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return stairs(n - 1) + stairs(n - 2);
}

/**
 * @description: 爬楼梯
 * @author: yuan wang
 * @date: 2023/08/10 10:24
 * @param: null
 * @return: null
 */
int main() {
    while (cin >> N) {
        cout << stairs(N) << endl;
    }
    return 0;
}
