/**
 * @BelongsProject: 02
 * @Author: yuan wang
 * @CreateTime: 2023-07-17  21:07
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
using namespace std;

/**
 * @description: 蟠桃记
 * @author: yuan wang
 * @date: 2023/07/17 21:07
 * @param: null
 * @return: null
 */
int main() {
    int n = 0;
    while (cin >> n) {
        int num = 1;
        for (int i = 1; i < n; ++i) {
            num = (num + 1) * 2;
        }
        cout << num << endl;
    }
    return 0;
}
