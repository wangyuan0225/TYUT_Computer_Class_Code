/**
 * @BelongsProject: Others
 * @Author: yuan wang
 * @CreateTime: 2023-08-09  14:57
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int factor_value();

int term_value();

int expression_value();

/**
 * @description: 计算表达式
 * @author: yuan wang
 * @date: 2023/08/09 14:57
 * @param: null
 * @return: null
 */
int main() {
    cout << expression_value() << endl;
    return 0;
}

/**
 * 求一个表达式的值
 * @return 值
 */
int expression_value() {
    //求第一个项的值
    int result = term_value();
    while (true) {
        //看一个字符，不取走
        char op = cin.peek();
        if (op == '+' || op == '-') {
            //从输入中取走一个字符
            cin.get();
            int value = term_value();
            if (op == '+') {
                result += value;
            } else {
                result -= value;
            }
        } else break;
    }
    return result;
}

/**
 * 求一个项的值
 * @return
 */
int term_value() {
    //求第一个因子的值
    int result = factor_value();
    while (true) {
        char op = cin.peek();
        if (op == '*' || op == '/') {
            cin.get();
            int value = factor_value();
            if (op == '*') {
                result *= value;
            } else {
                result /= value;
            }
        } else break;
    }
    return result;
}

/**
 * 求一个因子的值
 * @return
 */
int factor_value() {
    int result = 0;
    char c = cin.peek();
    if (c == '(') {
        //扔掉左括号
        cin.get();
        result = expression_value();
        //扔掉右括号
        cin.get();
    } else {
        while (isdigit(c)) {
            result = 10 * result + c - '0';
            cin.get();
            c = cin.peek();
        }
    }
    return result;
}
