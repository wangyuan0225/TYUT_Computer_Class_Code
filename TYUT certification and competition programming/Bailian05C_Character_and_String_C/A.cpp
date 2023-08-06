/**
 * @BelongsProject: Bailian05C_Character_and_String_C
 * @Author: yuan wang
 * @CreateTime: 2023-07-25  14:24
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cstring>
using namespace std;

const int LENGTH = 31;

/**
 * @description: 字符替换
 * @author: yuan wang
 * @date: 2023/07/25 14:24
 * @param: null
 * @return: null
 */
int main() {
    char arr[LENGTH];
    cin >> arr;
    char former, later;
    cin >> former;
    cin >> later;
    for (int i = 0; i < strlen(arr); ++i) {
        if (arr[i] == former) {
            arr[i] = later;
        }
    }
    cout << arr;
    return 0;
}
