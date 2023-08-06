/**
*@BelongsProject: GeneralExercise-Demo01
*@Author: yuan wang
*@CreateTime: 2023-01-28  16:45
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>
#include <math.h>

/*
 * @description: 竹青遍野
 * @author: yuan wang
 * @date: 2023/1/28 16:46
 * @param: null
 * @return: null
 */
#include <math.h>
int main()
{
    int t, p = 0;
    int num[99];
    int result[99];
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &num[i]);
        for (int a = 0;; a++)
        {
            int all = 0;
            all += pow(a, 3);
            if (num[i] >= all && num[i] <= all + pow(a + 1, 3))
            {
                result[i] = a;
                break;
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        printf("%d\n", result[i] + 1);
    }
    return 0;
}