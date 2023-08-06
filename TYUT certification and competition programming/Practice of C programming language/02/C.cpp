/**
 * @BelongsProject: 02
 * @Author: yuan wang
 * @CreateTime: 2023-07-17  16:00
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cmath>
using namespace std;

/**
 * @description: 求数列的和
 * @author: yuan wang
 * @date: 2023/07/17 16:00
 * @param: null
 * @return: null
 */
int main() {
    int n = 0;
    while (cin >> n) {
        int m = 0;
        cin >> m;
        double sum = 0;
        double tmp = n;
        for (int i = 0; i < m; ++i) {
            sum += tmp;
            tmp = sqrt(tmp);
        }
        printf("%.2f\n", sum);
    }
    return 0;
}
