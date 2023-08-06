/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-15  08:44
 * @Description: TODO:修改了精度，输入double，输出float
 * @Version: 2.0
 */

#include <iostream>
#include <cmath>

using namespace std;

/**
 * @description: 求绝对值
 * @author: yuan wang
 * @date: 2023/07/15 08:44
 * @param: null
 * @return: null
 */
int main() {
    double x;
    while (cin >> x) {
        printf("%.2f\n", fabs(x));
    }
    return 0;
}
