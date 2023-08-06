/**
 * @BelongsProject: 03
 * @Author: yuan wang
 * @CreateTime: 2023-08-06  17:10
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
using namespace std;

/**
 * @description: 海选女主角
 * @author: yuan wang
 * @date: 2023/08/06 17:10
 * @param: null
 * @return: null
 */
int main() {
    int m, n;
    while (cin >> m) {
        cin >> n;
        int mm = m * n;
        int *score = new int[mm];
        for (int i = 0; i < mm; ++i) {
            cin >> score[i];
        }
        int tmp = 0;
        for (int i = 1; i < mm; ++i) {
            if (abs(score[i]) > abs(score[tmp])) {
                tmp = i;
            }
        }
        tmp++;
        if (tmp % n == 0) {
            cout << tmp / n << " " << n << " " << score[tmp - 1] << endl;
        } else {
            cout << tmp / n + 1 << " " << tmp % n  << " " << score[tmp - 1] << endl;
        }
    }
    return 0;
}
