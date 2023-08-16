/**
 * @BelongsProject: 04
 * @Author: yuan wang
 * @CreateTime: 2023-08-16  09:14
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

/**
 * @description: 汉字统计
 * @author: yuan wang
 * @date: 2023/08/16 09:14
 * @param: null
 * @return: null
 */
int main() {
    int n, a;
    cin >> n;
    cin.get();
    while (n--) {
        int count = 0;
        while (((a = cin.get()) != EOF) && a != '\n') {
            if (a > 127) {
                count++;
            }
        }
        cout << count / 3 << endl;
    }
    return 0;
}
