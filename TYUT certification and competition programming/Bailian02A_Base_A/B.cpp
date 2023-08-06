/**
 * @BelongsProject: Bailian02A_Base_A
 * @Author: yuan wang
 * @CreateTime: 2023-07-18  10:51
 * @Description: TODO: 手写任意进制转二进制，而不使用库函数strtol
 * @Version: 2.0
 */

#include <iostream>
#include <cmath>

using namespace std;

const char digits[] = "0123456789ABCDEF";

/**
 * @description: 数制转换
 * @author: yuan wang
 * @date: 2023/07/18 10:51
 * @param: null
 * @return: null
 */
int main() {
    int m, n;
    string s;
    cin >> m >> s >> n;
    long long ten = 0;
    int tmp;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'F') {
            tmp = s[i] - 'A' + 10;
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            tmp = s[i] - 'a' + 10;
        } else {
            tmp = s[i] - '0';
        }
        ten += tmp * pow(m, s.size() - i - 1);
    }

    string ans;
    do {
        ans += digits[ten % n];
    } while (ten /= n);
    for (int j = ans.size() - 1; j >= 0; --j) {
        cout << ans[j];
    }

    cout << endl;
    return 0;
}
