/**
 * @BelongsProject: 04
 * @Author: yuan wang
 * @CreateTime: 2023-08-14  16:29
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
using namespace std;

/**
 * @description: 首字母变大写
 * @author: yuan wang
 * @date: 2023/08/14 16:29
 * @param: null
 * @return: null
 */
int main() {
    int a;
    bool isFirst = true;
    while ((a = cin.get()) != EOF) {
        if (a == ' ' || a == '\n') {
            isFirst = true;
            cout << (char) a;
            continue;
        }
        if (isFirst && a >= 'a' && a <= 'z') {
            cout << (char) (a + 'A' - 'a');
        } else {
            cout << (char) a;
        }
        isFirst = false;
    }
    return 0;
}
