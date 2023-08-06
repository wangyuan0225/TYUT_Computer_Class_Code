/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-11  21:54
 * @Description: TODO
 * @Version: 1.0
 */

#include <stdio.h>
#include <string.h>

/**
 * @description: 成绩转换
 * @author: yuan wang
 * @date: 2023/07/11 21:54
 * @param: null
 * @return: null
 */
int main() {
    int a[99] = {0};
    int i = 0;
    char input[9];
    for (; i < 99; ++i) {
        fgets(input, 9, stdin);
        if (strcmp(input, "\n") == 0) {
            break;
        }
        sscanf(input, "%d", &a[i]);
    }
    for (int j = 0; j < i; ++j) {
        if (a[j] >= 90 && a[j] <= 100) {
            printf("A\n");
        } else if (a[j] >= 80 && a[j] <= 89) {
            printf("B\n");
        } else if (a[j] >= 70 && a[j] <= 79) {
            printf("C\n");
        } else if (a[j] >= 60 && a[j] <= 69) {
            printf("D\n");
        } else if (a[j] >= 0 && a[j] <= 59) {
            printf("E\n");
        } else {
            printf("Score is error!\n");
        }
    }
    return 0;
}
