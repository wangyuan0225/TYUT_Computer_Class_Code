/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-12  09:40
 * @Description: TODO
 * @Version: 1.0
 */

#include <stdio.h>
#include <string.h>

/**
 * @description: 第几天？
 * @author: yuan wang
 * @date: 2023/07/12 09:40
 * @param: null
 * @return: null
 */
int main() {
    int year[99], month[99], day[99];
    int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum[99] = {0};
    char input[12];
    int i = 0;
    for (; i < 99; i++) {
        fgets(input, 12, stdin);
        if (strcmp(input, "\n") == 0) {
            break;
        }
        sscanf(input, "%d/%d/%d", &year[i], &month[i], &day[i]);
    }
    for (int j = 0; j < i; ++j) {
        if ((year[j] % 4 == 0 && year[j] % 100 != 0) || year[j] % 400 == 0) {
            month_day[1] = 29;
        }
        for (int k = 0; k < month[j] - 1; ++k) {
            sum[j] += month_day[k];
        }
        sum[j] += day[j];
        printf("%d\n", sum[j]);
    }
    return 0;
}
