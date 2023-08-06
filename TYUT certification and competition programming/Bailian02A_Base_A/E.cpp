/**
 * @BelongsProject: Bailian02A_Base_A
 * @Author: yuan wang
 * @CreateTime: 2023-07-18  13:29
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

long long sum(long long m);

/**
 * @description: 数根
 * @author: yuan wang
 * @date: 2023/07/18 13:29
 * @param: null
 * @return: null
 */
int main() {
    string start;
    while (cin >> start){
        long long m = 0;
        for (int i = 0; i < start.size(); ++i) {
            m += start[i] - '0';
        }
        while (m >= 10) {
            m = sum(m);
        }
        cout << m << endl;
    }
    return 0;
}

long long sum(long long m) {
    long long ans = 0;
    do {
        ans += m % 10;
    } while (m /= 10);
    return ans;
}
