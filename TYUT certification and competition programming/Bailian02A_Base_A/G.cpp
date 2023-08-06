/**
 * @BelongsProject: Bailian02A_Base_A
 * @Author: yuan wang
 * @CreateTime: 2023-07-18  11:17
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

/**
 * @description: 与3和5无关的数
 * @author: yuan wang
 * @date: 2023/07/18 11:17
 * @param: null
 * @return: null
 */
int main() {
    int n = 0;
    cin >> n;
    int sum = 0;
    if (n < 10) {
        for (int i = 1; i <= n; ++i) {
            if (i != 5 && i % 3 != 0) {
                sum += i * i;
            }
        }
        cout << sum << endl;
    } else if (n >= 10 && n <= 99) {
        for (int i = 10; i <= n; ++i) {
            if ((i / 10 != 5) && (i % 10 != 5) && (i % 5 != 0) && (i / 10 != 3) && (i % 10 != 3) && (i % 3 != 0)) {
                sum += i * i;
            }
        }
        cout << sum + 134 << endl;
    } else {
        for (int i = 100; i <= n; ++i) {
            if ((i / 100 != 5) && (i % 100 / 10 != 5) && (i % 5 != 0) && (i / 100 != 3) && (i % 100 / 10 != 3) &&
                (i % 10 != 3) &&
                (i % 3 != 0)) {
                sum += i * i;
            }
        }
        cout << sum + 138101 << endl;
    }
    return 0;
}
