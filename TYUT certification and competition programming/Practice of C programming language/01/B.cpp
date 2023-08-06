/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-14  21:47
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cstring>

using namespace std;

/**
 * @description: ASCII码排序
 * @author: yuan wang
 * @date: 2023/07/14 21:47
 * @param: null
 * @return: null
 */
int main() {
    char arr[99];
    char input[5];
    char tmp;
    int i = 0;
    for (; i < 99; i += 3) {
        cin.getline(input, 5);
        if (strcmp(input, "\0") == 0) {
            break;
        }
        sscanf(input, "%c%c%c", &arr[i], &arr[i + 1], &arr[i + 2]);
    }
    for (int k = 0; k < i; k += 3) {
        for (int j = 0; j < 2; ++j) {
            for (int l = k; l < k + 2 - j; ++l) {
                if (arr[l] > arr[l + 1]) {
                    tmp = arr[l];
                    arr[l] = arr[l + 1];
                    arr[l + 1] = tmp;
                }
            }
        }
    }
    for (int k = 0; k < i; k += 3) {
        cout << arr[k] << " " << arr[k + 1] << " " << arr[k + 2] << endl;
    }
    return 0;
}
