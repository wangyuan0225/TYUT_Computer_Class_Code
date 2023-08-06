/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-11  21:50
 * @Description: TODO
 * @Version: 1.0
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

/**
 * @description: 求绝对值
 * @author: yuan wang
 * @date: 2023/07/11 21:50
 * @param: null
 * @return: null
 */
int main() {
    float a[99] = {0};
    int i = 0;
    char input[9];
    for (; i < 99; ++i) {
        fgets(input, 9, stdin);
        if (strcmp(input, "\n") == 0) {
            break;
        }
        sscanf(input, "%f", &a[i]);
    }
    for (int j = 0; j < i; ++j) {
        printf("%.2f\n", fabsf(a[j]));
    }
    return 0;
}
