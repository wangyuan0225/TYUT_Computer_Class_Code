/**
*@BelongsProject: GeneralExercise-Demo02
*@Author: yuan wang
*@CreateTime: 2023-02-04  08:34
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>
#include <math.h>

/*
 * @description: 无剑无我
 * 小提示：两点之间距离+三角形两边之和大于第三边
 * 总结：编程题也需要很多的数学功底，计算机是死的，但人是活的
 * @author: yuan wang
 * @date: 2023/02/04 08:34
 * @param: null
 * @return: null
 */
int main() {
    int t;
    int a, b, c, d;

    float result[1024];

    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        result[i] = sqrt((a - c) * (a - c) + (b - d)*(b - d));
    }
    for (int i = 0; i < t; ++i) {
        printf("%.1lf\n", result[i]);
    }
    return 0;
}
