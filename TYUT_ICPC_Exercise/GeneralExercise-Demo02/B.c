/**
*@BelongsProject: GeneralExercise-Demo02
*@Author: yuan wang
*@CreateTime: 2023-01-29  13:39
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>

/*
 * @description: 统计同成绩学生人数
 * @author: yuan wang
 * @date: 2023/1/29 23:44
 * @param: null
 * @return: null
 */
int main() {
    int n;
    int counts[1024];
    int m = 0;
    while (1) {
        int count;
        scanf("%d", &n);
        if (n == 0) {
            break;
        } else {
            int score[n];
            for (int i = 0; i < n; ++i) {
                scanf("%d", &score[i]);
            }
            int definedScore;
            scanf("%d", &definedScore);
            count = 0;
            for (int i = 0; i < n; ++i) {
                if (score[i] == definedScore) {
                    count++;
                }
            }
            counts[m] = count;
            m++;
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", counts[i]);
    }
}
