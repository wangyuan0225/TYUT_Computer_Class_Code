/**
 * @BelongsProject: 02
 * @Author: yuan wang
 * @CreateTime: 2023-07-17  20:42
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cmath>

using namespace std;

int change(int n);
bool pd(int n);

/**
 * @description: 素数判定
 * @author: yuan wang
 * @date: 2023/07/17 20:42
 * @param: null
 * @return: null
 */
int main() {
    int x, y;
    while (1) {
        bool exist = false;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            break;
        }
        for (int i = x; i <= y; ++i) {
            if (pd(change(i))) {
                exist = true;
            }
        }
        if (exist) {
            cout << "Sorry" << endl;
        } else {
            cout << "OK" << endl;
        }
    }
    return 0;
}

/**
 * 计算表达式转换后的n
 * @param n
 * @return
 */
int change(int n) {
    return (n * n + n + 41);
}

/**
 * 判定是否为素数
 * @param n
 * @return
 */
bool pd(int n) {
    if (n % 2 == 0) {
        return true;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return true;
        }
    }
    return false;
}
