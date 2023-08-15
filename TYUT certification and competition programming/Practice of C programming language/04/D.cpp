/**
 * @BelongsProject: 04
 * @Author: yuan wang
 * @CreateTime: 2023-08-15  14:17
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 101

/**
 * @description: 统计元音
 * @author: yuan wang
 * @date: 2023/08/15 14:17
 * @param: null
 * @return: null
 */
int main() {
    int n;
    cin >> n;
    cin.get();
    while (n--) {
        int a = 0, e = 0, i = 0, o = 0, u = 0;
        char arr[MAX];
        cin.getline(arr, MAX);
        int size = strlen(arr);
        for (int j = 0; j < size; ++j) {
            if (arr[j] == 'a' || arr[j] == 'A') {
                a++;
            } else if (arr[j] == 'e' || arr[j] == 'E') {
                e++;
            } else if (arr[j] == 'i' || arr[j] == 'I') {
                i++;
            } else if (arr[j] == 'o' || arr[j] == 'O') {
                o++;
            } else if (arr[j] == 'u' || arr[j] == 'U') {
                u++;
            }
        }
        cout << "a:" << a << endl;
        cout << "e:" << e << endl;
        cout << "i:" << i << endl;
        cout << "o:" << o << endl;
        cout << "u:" << u << endl;
        if (n != 0) {
            cout << endl;
        }
    }
    return 0;
}
