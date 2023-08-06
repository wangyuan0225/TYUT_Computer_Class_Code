/**
*@BelongsProject: GeneralExercise-Demo02
*@Author: yuan wang
*@CreateTime: 2023-02-04  09:13
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>

/*
 * @description:
 * @author: yuan wang
 * @date: 2023/02/04 09:13
 * @param: null
 * @return: null
 */
int main() {
    int c;
    int n;
    scanf("%d", &c);

    int arr[11];
    int result[c];

    int tmp;
    for (int k = 0; k < c; k++) {
        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                if (arr[j + 1] < arr[j]) {
                    tmp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        result[k] = arr[1];
    }
    for (int i = 0; i < c; ++i) {
        printf("%d\n", result[i]);
    }
    return 0;
}
