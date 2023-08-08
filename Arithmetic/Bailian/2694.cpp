/**
 * @BelongsProject: Bailian
 * @Author: yuan wang
 * @CreateTime: 2023-08-08  17:43
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/**
 * 读入一个波兰表达式，并计算其值
 * @return
 */
double exp() {
    char s[20];
    cin >> s;
    switch (s[0]) {
        case '+':
            return exp() + exp();
        case '-':
            return exp() - exp();
        case '*':
            return exp() * exp();
        case '/':
            return exp() / exp();
        default:
            return atof(s);
    }
}

/**
 * @description: 波兰表达式
 * @author: yuan wang
 * @date: 2023/08/08 17:43
 * @param: null
 * @return: null
 */
int main() {
    printf("%lf", exp());
    return 0;
}
