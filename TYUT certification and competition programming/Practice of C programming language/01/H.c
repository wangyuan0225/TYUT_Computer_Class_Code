/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-12  10:36
 * @Description: TODO
 * @Version: 1.0
 */

#include <stdio.h>
#include <string.h>

/**
 * @description: 求奇数的乘积
 * @author: yuan wang
 * @date: 2023/07/12 10:36
 * @param: null
 * @return: null
 */
int main() {
    int arr[99][99] = {0};
    int ans[99] = {0};
    int i = 0;
    char input[199];

    for (; i < 99; i++) {
        fgets(input, 199, stdin);
        if (i != 0) {
            if (strcmp(input, "\n") == 0) {
                break;
            }
        }
        sscanf(input, "%d", &arr[i][0]);
        int offset = 2;
        for (int j = 1; j <= arr[i][0]; ++j) {
            sscanf(input + offset, "%d", &arr[i][j]);
            offset += 2;
        }
    }
    for (int j = 0; j < i; j++) {
        ans[j] = 1;
        for (int k = 1; k <= arr[j][0]; ++k) {
            if (arr[j][k] % 2 != 0) {
                ans[j] *= arr[j][k];
            }
        }
        printf("%d\n", ans[j]);
    }
    return 0;
}
