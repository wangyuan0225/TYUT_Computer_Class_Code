/**
 * @BelongsProject: Bailian05C_Character_and_String_C
 * @Author: yuan wang
 * @CreateTime: 2023-07-28  10:44
 * @Description: TODO:修正了很多问题，重复打印NO以及tmp的初始化问题
 * @Version: 2.0
 */

#include <iostream>

using namespace std;

/**
 * @description: 邮箱验证
 * @author: yuan wang
 * @date: 2023/07/28 10:44
 * @param: null
 * @return: null
 */
int main() {
    string s;
    while (cin >> s) {
        int at = 0, dot = 0;
        bool legal = false;
        int size = s.size();
        int tmp = size;
        if (s[0] == '@' || s[0] == '.' || s[size - 1] == '@' || s[size - 1] == '.') {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < size; ++i) {
            if (s[i] == '@') {
                at++;
                if (s[i + 1] == '.') {
                    legal = false;
                    break;
                }
                tmp = i;
            }
            if (s[i] == '.') {
                dot++;
                if (s[i + 1] == '@') {
                    legal = false;
                    break;
                }
                if (i > tmp) {
                    legal = true;
                }
            }
        }
        if (at != 1 || !legal) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
