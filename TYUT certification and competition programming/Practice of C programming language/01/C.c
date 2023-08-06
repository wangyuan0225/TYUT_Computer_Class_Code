/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-11  15:20
 * @Description: TODO: C语言二改优化版本，优化了换行结束方式
 * @Version: 2.0
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

/**
 * @description: 计算两点间的距离
 * @author: yuan wang
 * @date: 2023/07/11 15:20
 * @param: null
 * @return: null
 */
int main() {
    int x1[99], y1[99], x2[99], y2[99];
    char input[9];
    int i = 0;
    for (; i < 99; i++) {
        fgets(input, 9, stdin);
        if (strcmp(input, "\n") == 0) {
            break;
        }
        sscanf(input, "%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
    }
    for (int j = 0; j < i; ++j) {
        printf("%.2f\n", sqrt(pow(x1[j] - x2[j], 2) + pow(y1[j] - y2[j], 2)));
    }
    return 0;
}
