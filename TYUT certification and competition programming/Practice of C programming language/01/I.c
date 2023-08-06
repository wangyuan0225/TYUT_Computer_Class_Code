/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-12  12:13
 * @Description: TODO
 * @Version: 1.0
 */

#include <stdio.h>
#include <string.h>

/**
 * @description: 平方和与立方和
 * @author: yuan wang
 * @date: 2023/07/12 12:13
 * @param: null
 * @return: null
 */
int main() {
    int x[99] = {0};
    int y[99] = {0};
    int sumOdd[99] = {0};
    int sumEven[99] = {0};
    int i = 0;
    char input[5];
    for (; i < 99; i++) {
        fgets(input, 5, stdin);
        if (strcmp(input, "\n") == 0) {
            break;
        }
        sscanf(input, "%d%d", &x[i], &y[i]);
    }
    for (int j = 0; j < i; ++j) {
        for (int k = x[j]; k <= y[j]; ++k) {
            if (k % 2 == 0) {
                sumEven[j] += k * k;
            } else {
                sumOdd[j] += k * k * k;
            }
        }
        printf("%d %d\n", sumEven[j], sumOdd[j]);
    }
    return 0;
}
