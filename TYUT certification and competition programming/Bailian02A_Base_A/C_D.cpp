/**
 * @BelongsProject: Bailian02A_Base_A
 * @Author: yuan wang
 * @CreateTime: 2023-07-18  12:34
 * @Description: TODO:手写十进制和八进制的互相转换，而不使用库函数strtol
 * @Version: 2.0
 */

#include <iostream>
#include <cmath>

using namespace std;

int ans[6];
int i = 0;

void ten_convert_to_eight(int a);
void eight_convert_to_ten(int a);

/**
 * @description: 十进制到八进制&&八进制到十进制
 * @author: yuan wang
 * @date: 2023/07/18 12:34
 * @param: null
 * @return: null
 */
int main() {
    unsigned int a;
    cin >> a;

//    ten_convert_to_eight(a);
    eight_convert_to_ten(a);
}

void ten_convert_to_eight(int a) {
    do {
        ans[i] = a % 8;
        i++;
    } while (a /= 8);

    for (--i; i >= 0; --i) {
        cout << ans[i];
    }
}

void eight_convert_to_ten(int a) {
    int result = 0;
    do {
        ans[i] = a % 10;
        i++;
    } while (a /= 10);

    for (int j = 0; j < i; ++j) {
        result += ans[j] * pow(8, j);
    }
    cout << result;
}