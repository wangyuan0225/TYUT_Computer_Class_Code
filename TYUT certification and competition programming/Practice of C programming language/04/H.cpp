/**
 * @BelongsProject: 04
 * @Author: yuan wang
 * @CreateTime: 2023-08-12  15:24
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
using namespace std;

const char digits[] = "0123456789ABCDEF";
/**
 * @description: 进制转换
 * @author: yuan wang
 * @date: 2023/08/12 15:24
 * @param: null
 * @return: null
 */
int main() {
    int ten, n;
    while (cin >> ten >> n) {
        string ans;
        if (ten < 0) {
            cout << "-";
        }
        ten = abs(ten);
        do {
            ans += digits[ten % n];
        } while (ten /= n);
        for (int j = ans.size() - 1; j >= 0; --j) {
            cout << ans[j];
        }
        cout << endl;
    }
    return 0;
}
