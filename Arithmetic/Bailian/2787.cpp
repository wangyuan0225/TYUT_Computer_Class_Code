/**
 * @BelongsProject: Bailian
 * @Author: yuan wang
 * @CreateTime: 2023-08-10  16:16
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cmath>

using namespace std;
double a[5];
#define EPS 1e-6

/**
 * 用于判断x绝对值是否为0
 * @param x
 * @return
 */
bool isZero(double x) {
    return fabs(x) <= EPS;
}

/**
 * 用数组 a 的 n 个数判断能否算24
 * @param a
 * @param n
 * @return
 */
bool count24(double a[], int n) {
    if (n == 1) {
        if (isZero(a[0] - 24))
            return true;
        else
            return false;
    }
    double b[5];
    //枚举两个数的组合
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            //用于标识剩下的数的下标并存入b
            int m = 0;
            for (int k = 0; k < n; ++k) {
                if (k != i && k != j) {
                    b[m++] = a[k];
                }
            }
            b[m] = a[i] + a[j];
            if (count24(b, m + 1)) {
                return true;
            }
            b[m] = a[i] - a[j];
            if (count24(b, m + 1)) {
                return true;
            }
            b[m] = a[j] - a[i];
            if (count24(b, m + 1)) {
                return true;
            }
            b[m] = a[i] * a[j];
            if (count24(b, m + 1)) {
                return true;
            }
            if (!isZero(a[j])) {
                b[m] = a[i] / a[j];
                if (count24(b, m + 1)) {
                    return true;
                }
            }
            if (!isZero(a[i])) {
                b[m] = a[j] / a[i];
                if (count24(b, m + 1)) {
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * @description:算24
 * @author: yuan wang
 * @date: 2023/08/10 16:16
 * @param: null
 * @return: null
 */
int main() {
    while (true) {
        for (int i = 0; i < 4; ++i) {
            cin >> a[i];
        }
        if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) {
            return 0;
        }
        if(count24(a, 4)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
