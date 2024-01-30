/**
 * @BelongsProject: 03
 * @Author: yuan wang
 * @CreateTime: 2023-08-06  10:11
 * @Description: TODO
 * @Version: 2.0 改进了算法，并用数组进行存储
 */

#include <iostream>

using namespace std;

int cows[55];

void calculateCows() {
    cows[1] = 1;
    cows[2] = 2;
    cows[3] = 3;

    for (int i = 4; i < 55; i++) {
        cows[i] = cows[i - 1] + cows[i - 3];
    }
}

int main() {
    calculateCows();
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << cows[n] << endl;
    }
    return 0;
}
