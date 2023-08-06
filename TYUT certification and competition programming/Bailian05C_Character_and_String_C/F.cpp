/**
 * @BelongsProject: Bailian05C_Character_and_String_C
 * @Author: yuan wang
 * @CreateTime: 2023-07-28  18:11
 * @Description: TODO:总感觉与D有异曲同工之妙
 * @Version: 1.0
 */

#include <iostream>
using namespace std;

/**
 * @description: 子串
 * @author: yuan wang
 * @date: 2023/07/28 18:11
 * @param: null
 * @return: null
 */
int main() {
    string s, t;
    while (cin >> s) {
        cin >> t;
        int i = 0;
        if (s.size() > t.size()) {
            cout << "No" << endl;
            continue;
        }
        for (int j = 0; j < t.size(); ++j) {
            if (t[j] == s[i]) {
                i++;
                continue;
            }
        }
        if (i == s.size()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
