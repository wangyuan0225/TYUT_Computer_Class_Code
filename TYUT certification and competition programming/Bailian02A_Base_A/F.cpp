/**
 * @BelongsProject: Bailian02A_Base_A
 * @Author: yuan wang
 * @CreateTime: 2023-07-18  12:41
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cmath>
using namespace std;

const char digits[] = "0123456789ABCDEF";

/**
 * @description: 2进制转化为16进制
 * @author: yuan wang
 * @date: 2023/07/18 12:41
 * @param: null
 * @return: null
 */
int main() {
    int n;
    cin >> n;
    string arr;
    while (n--) {
        cin >> arr;
        int size = arr.size();
        if (size % 4 != 0) {
            int index = 0;
            for (int i = 0; i < size % 4; ++i) {
                index += (arr[size % 4 - i - 1] - '0') * pow(2, i);
            }
            cout << digits[index];
            for (int i = size % 4; i < size; i += 4) {
                index = (arr[i] - '0') * 8 + (arr[i + 1] - '0') * 4 + (arr[i + 2] - '0') * 2 + (arr[i + 3] - '0');
                cout << digits[index];
            }
        } else {
            int index = 0;
            for (int i = 0; i < size; i += 4) {
                index = (arr[i] - '0') * 8 + (arr[i + 1] - '0') * 4 + (arr[i + 2] - '0') * 2 + (arr[i + 3] - '0');
                cout << digits[index];
            }
        }
        cout << endl;
    }
    return 0;
}
