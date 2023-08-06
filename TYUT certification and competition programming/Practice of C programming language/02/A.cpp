/**
 * @BelongsProject: 02
 * @Author: yuan wang
 * @CreateTime: 2023-07-17  10:22
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
using namespace std;

/**
 * @description: A+B for Input-Output Practice (II)
 * @author: yuan wang
 * @date: 2023/07/17 10:22
 * @param: null
 * @return: null
 */
int main() {
    int n = 0;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}
