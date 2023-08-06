/**
*@BelongsProject: GeneralExercise-Demo03
*@Author: yuan wang
*@CreateTime: 2023-02-07  11:08
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>

/*
 * @description: 七夕节
 * @author: yuan wang
 * @date: 2023/02/07 11:08
 * @param: null
 * @return: null
 */
int main() {
    int t;
    scanf("%d", &t);

    int result[t];

    int n;
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        result[i] = 0;
        for (int j = 1; j < n; ++j) {
            if (n % j == 0) {
                result[i] += j;
            }
        }
    }

    for (int i = 0; i < t; ++i) {
        printf("%d\n", result[i]);
    }

    return 0;
}


