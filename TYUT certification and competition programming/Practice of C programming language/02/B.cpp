/**
 * @BelongsProject: 02
 * @Author: yuan wang
 * @CreateTime: 2023-07-17  10:27
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

/**
 * @description: 数值统计
 * @author: yuan wang
 * @date: 2023/07/17 10:27
 * @param: null
 * @return: null
 */
int main() {
    int n = 0;
    while (1) {
        cin >> n;
        if (n == 0) {
            break;
        }
        int negative = 0, zero = 0, positive = 0;
        for (int i = 0; i < n; ++i) {
            float num = 0;
            cin >> num;
            if (num == 0) {
                zero++;
            } else if (num < 0) {
                negative++;
            } else {
                positive++;
            }
        }
        cout << negative << " " << zero << " " << positive << endl;
    }

    return 0;
}
