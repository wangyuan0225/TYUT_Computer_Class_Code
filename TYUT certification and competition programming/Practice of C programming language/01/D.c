/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-11  20:24
 * @Description: TODO
 * @Version: 1.0
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

#define PI 3.1415927

/**
 * @description: 计算球体积
 * @author: yuan wang
 * @date: 2023/07/11 20:24
 * @param: null
 * @return: null
 */
int main() {
    float r[99] = {0};
    int i = 0;
    char input[5];
    for (; i < 99; ++i) {
        fgets(input, 5, stdin);
        if (strcmp(input, "\n") == 0) {
            break;
        }
        sscanf(input, "%f", &r[i]);
    }
    for (int j = 0; j < i; ++j) {
        printf("%.3f\n", 4.0 / 3 * PI * pow(r[j], 3));
    }
    return 0;
}



