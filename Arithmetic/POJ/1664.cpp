/**
 * @BelongsProject: POJ
 * @Author: yuan wang
 * @CreateTime: 2023-08-10  11:14
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

/**
 * 计算 i 个苹果放在 k 个盘子里的方法总数
 * @param i
 * @param k
 * @return
 */
int f(int i, int k) {
    if (k > i)
        return f(i, i);
    if (i == 0)
        return 1;
    if (k == 0)
        return 0;
    return f(i, k - 1) + f(i - k, k);
}

/**
 * @description: 放苹果
 * @author: yuan wang
 * @date: 2023/08/10 11:14
 * @param: null
 * @return: null
 */
int main() {
    int t, m, n;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        cout << f(m, n) << endl;
    }
    return 0;
}
