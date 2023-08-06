/**
*@BelongsProject: GeneralExercise-Demo01
*@Author: yuan wang
*@CreateTime: 2023-01-28  17:07
*@Description: TODO
*@Version: 1.0
*/


#include <stdio.h>
#include <string.h>

/*
 * @description: 吃糖果
 * @author: yuan wang
 * @date: 2023/1/28 17:08
 * @param: null
 * @return: null
 */
int main() {
    int T;
    int N[99];
    int Mi[99][99] = { 0 };
    char answer[99][99] = { "" };
    int a[99] = { 0 };
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N[i]);
        for (int j = 0; j < N[i]; j++) {
            scanf("%d", &Mi[i][j]);
        }
    }
    for (int i = 0; i < T;) {
        for (int j = 0; j < N[i]; j++) {
            Mi[i][j]--;
        }
        for (int j = 0; j < N[i]; j++) {
            if (Mi[i][j] < 0)
                a[i]++;
        }
        if (a[i] == N[i] - 1)
            i++;
        else if (a[i] == N[i]) {
            strcpy(answer[i], "Yes");
            i++;
        }
        else
            a[i] = 0;
    }
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < N[i]; j++) {
            if (Mi[i][j] >= 0) {
                if (Mi[i][j] >= 1)
                    strcpy(answer[i], "NO");
                else
                    strcpy(answer[i], "Yes");
            }
        }
    }
    for (int i = 0; i < T; i++) {
        printf("%s\n", answer[i]);
    }
    return 0;
}