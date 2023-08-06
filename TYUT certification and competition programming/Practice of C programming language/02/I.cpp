/**
 * @BelongsProject: 02
 * @Author: yuan wang
 * @CreateTime: 2023-07-18  09:30
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

int count(int i, int m);

/**
 * @description: 偶数求和
 * @author: yuan wang
 * @date: 2023/07/18 09:30
 * @param: null
 * @return: null
 */
int main() {
    int m, n;
    while (cin >> n) {
        cin >> m;
        int *average = new int[n / m + 1]();
        if (n % m == 0) {
            for (int i = 0; i < n / m; ++i) {
                average[i] = count(i, m);
            }
            for (int i = 0; i < n / m; ++i) {
                cout << average[i] << " ";
            }
        } else {
            for (int i = 0; i < n / m; ++i) {
                average[i] = count(i, m);
            }
            int tmp = 0;
            for (int i = n; i > n - n % m; --i) {
                tmp += 2 * i;
            }
            average[n / m] = tmp / (n % m);
            for (int i = 0; i < n / m + 1; ++i) {
                cout << average[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

int count(int i, int m) {
    int average = 0;
    int start = 2;
    start += i * 2 * m;
    for (int j = 0; j < m; ++j) {
        average += start;
        start += 2;
    }
    return (average / m);
}