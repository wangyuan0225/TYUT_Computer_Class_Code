/**
*@BelongsProject: GeneralExercise-Demo02
*@Author: yuan wang
*@CreateTime: 2023-02-03  22:44
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>
#include <string.h>

/*
 * @description: 8球胜负
 * @author: yuan wang
 * @date: 2023/02/03 22:44
 * @param: null
 * @return: null
 */
int main() {
    int n;
    scanf("%d", &n);

    int r, y;
    char result[1024][7];
    char arr[1024] = " ";
    int m = 0;
    while (n != 0) {
        r = 0, y = 0;
        scanf("%s", arr);
        for (int i = 0; i < 1024; ++i) {
            if (arr[i] == 'R') {
                r++;
            } else if (arr[i] == 'Y') {
                y++;
            }
            if (arr[i] == '\000') {
                if (arr[i - 1] == 'B') {
                    if (r < 7) {
                        strcpy(result[m], "Yellow");
                    } else if (r == 7) {
                        strcpy(result[m], "Red");
                    }
                    m++;
                } else if (arr[i - 1] == 'L') {
                    if (y < 7) {
                        strcpy(result[m], "Red");
                    } else if (y == 7) {
                        strcpy(result[m], "Yellow");
                    }
                    m++;
                }
                break;
            }
        }
        scanf("%d", &n);
    }
    for (int i = 0; i < m; ++i) {
        printf("%s\n", result[i]);
    }
    return 0;
}
