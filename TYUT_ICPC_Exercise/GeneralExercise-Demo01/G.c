/**
*@BelongsProject: GeneralExercise-Demo01
*@Author: yuan wang
*@CreateTime: 2023-01-28  16:57
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>

/*
 * @description: 菜鸟先飞
 * @author: yuan wang
 * @date: 2023/1/28 16:58
 * @param: null
 * @return: null
 */
int main()
{
    int t;
    scanf("%d", &t);
    int time[99];
    int result[99];
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &time[i]);
        result[i] = time[i];
        for (int j = 0; j < time[i]; j++)
        {
            result[i] += 2 * j;
        }
    }
    for (int i = 0; i < t; i++)
    {
        printf("%d\n", result[i]);
    }
    return 0;
}