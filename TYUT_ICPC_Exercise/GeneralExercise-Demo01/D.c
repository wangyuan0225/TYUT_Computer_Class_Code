/**
*@BelongsProject: GeneralExercise-Demo01
*@Author: yuan wang
*@CreateTime: 2023-01-28  16:22
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>

/*
 * @description:两军交锋
 * @author: yuan wang
 * @date: 2023/1/28 16:32
 * @param: null
 * @return: null
 */
int main() {
    int T;
    scanf("%d", &T);
    float w[4];
    float *p = w;
    float result[99];
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%f", &w[j]);
        }
        //for (int j = 0; j < 4; j++)
        //{
        //	printf("%.3f \n", w[j]);
        //}
        result[i] = w[3] / (w[0] + w[1]) * w[2];
    }
    for (int i = 0; i < T; i++) {
        printf("%.3f ", result[i]);
    }
    return 0;
}