/**
*@BelongsProject: GeneralExercise-Demo02
*@Author: yuan wang
*@CreateTime: 2023-02-07  10:41
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>
#include <string.h>

/*
 * @description: 寻梦
 * @author: yuan wang
 * @date: 2023/02/07 10:41
 * @param: null
 * @return: null
 */
int main() {
    int n;
    scanf("%d", &n);

    char arr[n][50];

    char newarr[50];

    char result[n][101];

    for (int i = 0; i < n; ++i) {
        scanf("%s", arr[i]);
        scanf("%s", newarr);

        int k = 0;
        for (int j = 0; j < strlen(arr[i]) / 2; ++j) {
            result[i][k] = arr[i][j];
            k++;
        }

        for (int j = 0; j < strlen(newarr); ++j) {
            result[i][k] = newarr[j];
            k++;
        }

        for (int j = strlen(arr[i]) / 2; j < strlen(arr[i]); ++j) {
            result[i][k] = arr[i][j];
            k++;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%s\n", result[i]);
    }

    return 0;
}
