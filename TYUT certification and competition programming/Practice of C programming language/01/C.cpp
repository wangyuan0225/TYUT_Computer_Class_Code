/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-14  21:54
 * @Description: TODO: C++三改，重新考虑小数的情况
 * @Version: 3.0
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * @description: 计算两点间的距离
 * @author: yuan wang
 * @date: 2023/07/14 21:54
 * @param: null
 * @return: null
 */
int main() {
    float x1[99], y1[99], x2[99], y2[99];
    char input[99];
    int i = 0;
    for (; i < 99; i++) {
        cin.getline(input, 99);
        if (strcmp(input, "\0") == 0) {
            break;
        }
        sscanf(input, "%f %f %f %f", &x1[i], &y1[i], &x2[i], &y2[i]);
    }
    for (int j = 0; j < i; ++j) {
        cout << fixed << setprecision(2) << sqrt(pow(x1[j] - x2[j], 2) + pow(y1[j] - y2[j], 2)) << endl;
    }
    return 0;
}
