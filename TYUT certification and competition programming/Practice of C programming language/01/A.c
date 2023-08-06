/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-10  18:48
 * @Description: TODO: C语言二改优化版本，优化了换行结束方式
 * @Version: 2.0
 */

#include <stdio.h>
#include <string.h>

/**
 * @description: A + B Problem
 * @author: yuan wang
 * @date: 2023/07/10 18:48
 * @param: null
 * @return: null
 */
int main() {
    int arr[99] = {0};
    int i = 0;
    char input[9];
    for (; i < 99; i += 2) {
        fgets(input, 9, stdin);
        if (strcmp(input, "\n") == 0) {
            break;
        }
        sscanf(input, "%d %d", &arr[i], &arr[i + 1]);
    }
    for (int j = 0; j < i; j += 2) {
        printf("%d\n", arr[j] + arr[j + 1]);
    }
    return 0;
}
