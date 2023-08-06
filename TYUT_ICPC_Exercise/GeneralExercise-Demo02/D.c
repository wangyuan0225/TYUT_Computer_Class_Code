/**
*@BelongsProject: GeneralExercise-Demo02
*@Author: yuan wang
*@CreateTime: 2023-01-30  11:27
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>

/**
 * @description: 仙人球的残影
 * @author: yuan wang
 * @date: 2023/01/30 11:27
 * @param: null
 * @return: null
 */
int main() {
    int n;
    scanf("%d", &n);

    while (n != 0) {
        for (int i = 0; i < n; ++i) {
            printf("%d   ", i + 1);
        }
        printf("\n");
        for (int i = 0; i < n - 2; ++i) {
            printf("%d", 4 * (n - 1) - i);
            for (int j = 0; j < 4 * n - 5; ++j) {
                printf(" ");
            }
            printf("%d\n", n + i + 1);
        }
        for (int i = 0; i < n; ++i) {
            printf("%d   ", 3 * n - 2 - i);
        }
        printf("\n");
        scanf("%d", &n);
    }

    return 0;
}
