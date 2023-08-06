/**
*@BelongsProject: GeneralExercise-Demo03
*@Author: yuan wang
*@CreateTime: 2023-02-08  15:41
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>
#include <string.h>

/*
 * @description: 统计字符
 * @author: yuan wang
 * @date: 2023/02/08 15:41
 * @param: null
 * @return: null
 */
int main() {
    char c[1024];
    char arr[1024];
    int n[99] = {0};
    char result[1024];

    gets(c);
    int k = 0;
    while (strcmp(c, "#")) {
        gets(arr);
        for (int i = 0; i < strlen(c); ++i) {
            result[k] = c[i];
            for (int j = 0; j < strlen(arr); ++j) {
                if (arr[j] == c[i]) {
                    n[k]++;
                }
            }
            k++;
        }
        gets(c);
    }

    for (int i = 0; i < k; ++i) {
        printf("%c %d\n", result[i], n[i]);
    }
    return 0;
}
