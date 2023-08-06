/**
 * @BelongsProject: 02
 * @Author: yuan wang
 * @CreateTime: 2023-07-17  20:18
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
using namespace std;

float calculate(int n);

/**
 * @description: 多项式求和
 * @author: yuan wang
 * @date: 2023/07/17 20:18
 * @param: null
 * @return: null
 */
int main() {
    int m, n;
    cin >> m;
    float *ans = new float[m]();
    for (int i = 0; i < m; ++i) {
        cin >> n;
        ans[i] = calculate(n);
    }
    for (int i = 0; i < m; ++i) {
        printf("%.2f\n", ans[i]);
    }
    return 0;
}

/**
 * 计算每一个整数n的前n项和
 * @param n
 * @return ans
 */
float calculate(int n) {
    float ans = 0;
    int sgn = 1;
    for (int i = 1; i <= n; ++i) {
        ans += sgn * 1.0 / i;
        sgn *= (-1);
    }
    return ans;
}
