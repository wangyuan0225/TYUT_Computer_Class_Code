/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-11  15:46
 * @Description: TODO: C++二改优化版本，优化了换行结束方式
 * @Version: 2.0
 */

#include <iostream>
#include <cstring>

using namespace std;

/**
 * @description: A + B Problem
 * @author: yuan wang
 * @date: 2023/07/11 15:46
 * @param: null
 * @return: null
 */
int main() {
    int arr[99] = {0};
    int i = 0;
    char input[9];
    for (; i < 99; i += 2) {
        cin.getline(input, 9);
        if (strcmp(input, "\0") == 0) {
            break;
        }
        sscanf(input, "%d %d", &arr[i], &arr[i + 1]);
    }
    for (int j = 0; j < i; j += 2) {
        cout << arr[j] + arr[j + 1] << endl;
    }
    return 0;
}
