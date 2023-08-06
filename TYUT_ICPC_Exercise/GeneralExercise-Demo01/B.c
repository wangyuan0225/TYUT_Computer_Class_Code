/**
*@BelongsProject: GeneralExercise-Demo01
*@Author: yuan wang
*@CreateTime: 2023-01-28  16:20
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>

/*
 * @description:分数矩阵
 * @author: yuan wang
 * @date: 2023/1/28 16:20
 * @param: null
 * @return: null
 */
int main() {
    int arr[99];
    int *p = arr;
    int len = 0;
    for (;; p++) {
        scanf("%d", p);
        if (*p == 0) {
            break;
        }
        len++;
    }
    //scanf("%d", arr);
    float all[99];
    for (int q = 0; q < len; q++) {

        int j = arr[q] - 1;
        all[q] = 0;
        for (int i = 2; i <= arr[q]; i++, j--) {
            all[q] += 1.00 / i * 2 * j;
        }
        all[q] += arr[q];
    }
    for (int q = 0; q < len; q++) {
        printf("%.2f\n", all[q]);
    }
    return 0;
}