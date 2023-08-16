/**
 * @BelongsProject: 04
 * @Author: yuan wang
 * @CreateTime: 2023-08-15  14:51
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

/**
 * @description: Lowest Common Multiple Plus
 * @author: yuan wang
 * @date: 2023/08/15 14:51
 * @param: null
 * @return: null
 */
int main() {
    int n;
    while (cin >> n) {
        unsigned long long int *arr = new unsigned long long int[n];
        cin >> arr[0];
        if (n == 1) {
            cout << arr[0] << endl;
            continue;
        } else {
            int max = arr[0];
            unsigned long long sum = arr[0];
            for (int i = 1; i < n; ++i) {
                cin >> arr[i];
                if (arr[i] > max) {
                    max = arr[i];
                }
                sum *= arr[i];
            }

            for (int i = max; i <= sum; i += max) {
                int count = 0;
                for (int j = 0; j < n; ++j) {
                    if (i % arr[j] != 0) {
                        break;
                    } else {
                        count++;
                    }
                }
                if (count == n) {
                    cout << i << endl;
                    break;
                }
            }

        }
        delete[]arr;
    }
    return 0;
}
