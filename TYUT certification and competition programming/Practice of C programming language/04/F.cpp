/**
 * @BelongsProject: 04
 * @Author: yuan wang
 * @CreateTime: 2023-08-16  08:38
 * @Description: TODO
 * @Version: 1.0
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @description: Palindromes _easy version
 * @author: yuan wang
 * @date: 2023/08/16 08:38
 * @param: null
 * @return: null
 */
int main() {
    int n;
    cin >> n;
    cin.get();
    while (n--) {
        string arr;
        getline(cin, arr);
        int size = arr.size();
        int j = size - 1;
        bool isPalindromes = true;
        for (int i = 0; i < size / 2; ++i, --j) {
            if (arr[i] != arr[j]) {
                cout << "no" << endl;
                isPalindromes = false;
                break;
            }
        }
        if (isPalindromes) {
            cout << "yes" << endl;
        }
    }
    return 0;
}
