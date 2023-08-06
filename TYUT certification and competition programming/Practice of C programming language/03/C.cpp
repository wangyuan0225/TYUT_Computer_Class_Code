/**
 * @BelongsProject: 03
 * @Author: yuan wang
 * @CreateTime: 2023-08-06  09:42
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
using namespace std;

/**
 * @description: 字符串统计
 * @author: yuan wang
 * @date: 2023/08/06 09:42
 * @param: null
 * @return: null
 */
int main() {
    int n;
    cin >> n;
    cin.get();
    while (n--) {
        int c;
        int count = 0;
        while ((c = cin.get()) != '\n') {
            if (c >= '0' && c <= '9') {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
