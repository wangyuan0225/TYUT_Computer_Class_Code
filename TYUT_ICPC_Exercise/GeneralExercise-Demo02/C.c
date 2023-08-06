/**
*@BelongsProject: GeneralExercise-Demo02
*@Author: yuan wang
*@CreateTime: 2023-01-30  10:33
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>

/*
 * @description:
 * @author: yuan wang
 * @date: 2023/01/30 10:33
 * @param: null
 * @return: null
 */
int main() {
    int x[1024];
    int y[1024];
    int n = 0;
    int m = 0;
    int minx[1024];
    int miny[1024];
    int maxx[1024];
    int maxy[1024];
    do {
        while (1) {
            scanf("%d%d", &x[n], &y[n]);
            if (x[n] == 0 && y[n] == 0) {
                break;
            } else {
                n++;
            }
        }
        minx[m] = x[0];
        for (int i = 0; i < n; ++i) {
            if(x[i] < minx[m]) {
                minx[m] = x[i];
            }
        }
        miny[m] = y[0];
        for (int i = 0; i < n; ++i) {
            if(y[i] < miny[m]) {
                miny[m] = y[i];
            }
        }
        maxx[m] = x[0];
        for (int i = 0; i < n; ++i) {
            if(x[i] > maxx[m]) {
                maxx[m] = x[i];
            }
        }
        maxy[m] = y[0];
        for (int i = 0; i < n; ++i) {
            if(y[i] > maxy[m]) {
                maxy[m] = y[i];
            }
        }
        m++;
        n = 0;
        scanf("%d%d", &x[n], &y[n]);
        n++;
    } while (x[n - 1] != 0 && y[n - 1] != 0);
    for (int i = 0; i < m; ++i) {
        printf("%d %d %d %d\n", minx[i], miny[i], maxx[i], maxy[i]);
    }
    return 0;
}
