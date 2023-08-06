/**
*@BelongsProject: GeneralExercise-Demo03
*@Author: yuan wang
*@CreateTime: 2023-02-08  15:25
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>

int wan(int j);

/*
 * @description:
 * @author: yuan wang
 * @date: 2023/02/08 15:25
 * @param: null
 * @return: null
 */
int main() {
    int n;
    scanf("%d", &n);

    int min, max;

    int result[99] = {0};

    int m = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &min);
        scanf("%d", &max);

        for (int j = min; j <= max; ++j) {
            if (j == wan(j)) {
                result[m]++;
            }
        }
        m++;
    }

    for (int i = 0; i < m; ++i) {
        printf("%d\n", result[i]);
    }

    return 0;
}

int wan(int j) {
    int yin[99];
    int m = 0;
    int result = 0;
    for (int i = 1; i <= j / 2; ++i) {
        if (j % i == 0) {
            yin[m] = i;
            m++;
        }
    }

    for (int i = 0; i < m; ++i) {
        result += yin[i];
    }
    return result;
}
