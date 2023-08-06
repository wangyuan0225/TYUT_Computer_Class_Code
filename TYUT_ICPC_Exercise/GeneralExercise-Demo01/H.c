/**
*@BelongsProject: GeneralExercise-Demo01
*@Author: yuan wang
*@CreateTime: 2023-01-28  17:05
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>

/*
 * @description: 奇偶位互换
 * @author: yuan wang
 * @date: 2023/1/28 17:06
 * @param: null
 * @return: null
 */
int  main()
{
    int C;
    scanf("%d", &C);
    char arr[99][99];
    for (int i = 0; i < C; i++)
    {
        scanf("%s", arr[i]);
        for (int j = 0; j < strlen(arr[i]); j += 2)
        {
            char tmp;
            tmp = arr[i][j + 1];
            arr[i][j + 1] = arr[i][j];
            arr[i][j] = tmp;
        }
    }
    for (int i = 0; i < C; i++)
    {
        printf("%s\n", arr[i]);
    }
    return 0;
}
