/**
 * @BelongsProject: 03
 * @Author: yuan wang
 * @CreateTime: 2023-08-06  08:29
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
using namespace std;

/**
 * @description: A+B for Input-Output Practice (IV)
 * @author: yuan wang
 * @date: 2023/08/06 08:29
 * @param: null
 * @return: null
 */
int main() {
    int n;
    while (cin >> n && n != 0) {
        int sum = 0, num;
        while (n--) {
            cin >> num;
            sum += num;
        }
        cout << sum << endl;
    }
    return 0;
}
