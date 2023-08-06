/**
*@BelongsProject: GeneralExercise-Demo03
*@Author: yuan wang
*@CreateTime: 2023-02-08  11:17
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>

int jishu(int m);

int oushu(int m);

/*
 * @description:
 * @author: yuan wang
 * @date: 2023/02/08 11:17
 * @param: null
 * @return: null
 */
int main() {

    int n;
    scanf("%d", &n);

    int k;

    int result[99][99] = {0};

    for (int i = 0; i < n; ++i) {
        int j = 0;
        scanf("%d", &k);

        while (result[i][j - 1] != 1) {
            if (k % 2 == 0) {
                k = oushu(k);
            } else {
                result[i][j] = k;
                k = jishu(k);
                j++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (result[i][0] == 1) {
            printf("No number can be output !");
        }
        for (int j = 0;; ++j) {
            if (result[i][j] == 1) {
                break;
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int jishu(int m) {
    return (m * 3 + 1);
}

int oushu(int m) {
    return m / 2;
}

