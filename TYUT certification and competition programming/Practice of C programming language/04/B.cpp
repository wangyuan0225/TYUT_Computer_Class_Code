/**
 * @BelongsProject: 04
 * @Author: yuan wang
 * @CreateTime: 2023-08-14  15:42
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 101

/**
 * @description: 查找最大元素
 * @author: yuan wang
 * @date: 2023/08/14 15:42
 * @param: null
 * @return: null
 */
int main() {
    char str[MAX];
    while (cin.getline(str, MAX)) {
        int size = strlen(str);
        char max = str[0];
        for (int i = 1; i < size; ++i) {
            if (str[i] > max) {
                max = str[i];
            }
        }
        for (int i = 0; i < size; ++i) {
            if (str[i] == max) {
                cout << str[i] << "(max)";
            } else {
                cout << str[i];
            }
        }
        cout << endl;
    }
    return 0;
}
