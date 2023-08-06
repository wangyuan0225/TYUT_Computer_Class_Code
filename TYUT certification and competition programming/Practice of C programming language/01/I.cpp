/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-16  22:59
 * @Description: TODO:二改，考虑了x > y的情况
 * @Version: 2.0
 */

#include <iostream>
#include <cstring>

using namespace std;

/**
 * @description: 平方和与立方和
 * @author: yuan wang
 * @date: 2023/07/16 22:59
 * @param: null
 * @return: null
 */
int main() {
    int *x = new int[99]();
    int *y = new int[99]();
    int *sumOdd = new int[99]();
    int *sumEven = new int[99]();
    int i = 0;
    char *input = new char[20]();
    for (; i < 99; i++) {
        cin.getline(input, 20);
        if (strcmp(input, "\0") == 0) {
            break;
        }
        sscanf(input, "%d%d", &x[i], &y[i]);
    }

    for (int j = 0; j < i; ++j) {
        int tmp;
        if (x[j] > y[j]) {
            tmp = x[j];
            x[j] = y[j];
            y[j] = tmp;
        }
        for (int k = x[j]; k <= y[j]; ++k) {
            if (k % 2 == 0) {
                sumEven[j] += k * k;
            } else {
                sumOdd[j] += k * k * k;
            }
        }
        cout << sumEven[j] << " " << sumOdd[j] << endl;
    }
    return 0;
}
