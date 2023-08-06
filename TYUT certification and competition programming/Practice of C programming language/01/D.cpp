/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-14  22:04
 * @Description: TODO: C++四改，提升精度，并将输出改为单精度浮点输出
 * @Version: 4.0
 */

#include <iostream>
#include <cmath>
#include <cstring>

const double PI = 3.1415927;
using namespace std;

/**
 * @description: 计算球体积
 * @author: yuan wang
 * @date: 2023/07/14 22:04
 * @param: null
 * @return: null
 */
int main() {
    double r;
    while (cin >> r) {
        printf("%.3f\n", 4.0 / 3 * PI * pow(r, 3));
    }
    return 0;
}

