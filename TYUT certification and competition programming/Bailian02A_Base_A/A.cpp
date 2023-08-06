/**
 * @BelongsProject: Bailian02A_Base_A
 * @Author: yuan wang
 * @CreateTime: 2023-07-18  10:30
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

/**
 * @description: 与7无关的数
 * @author: yuan wang
 * @date: 2023/07/18 10:30
 * @param: null
 * @return: null
 */
int main() {
    int n = 0;
    cin >> n;
    int sum = 0;
    if (n < 10) {
        for (int i = 1; i <= n; ++i) {
            if (i != 7) {
                sum += i * i;
            }
        }
        cout << sum << endl;
    } else {
        for (int i = 10; i <= n; ++i) {
            if ((i / 10 != 7) && (i % 10 != 7) && (i % 7 != 0)) {
                sum += i * i;
            }
        }
        cout << sum + 236 << endl;
    }
    return 0;
}
