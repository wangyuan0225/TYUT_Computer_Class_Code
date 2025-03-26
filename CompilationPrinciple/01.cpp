/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : OS
  * @File           : 01.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/12/19 14:08
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <bits/stdc++.h>

using namespace std;
const int N = 100;
char ch[N];    //存放输入的符号串
int cnt;

void unsigned_number();    //识别无符号数并输出
int float_number(int b);

int _E(int b);

void print(int hh, int tt);

int main() {
    cnt = 0;
    for (;;) {  //输入字符串
        cin >> ch[cnt];
        if (ch[cnt] == ';') break;    //字符串以;结束
        cnt++;
    }
    unsigned_number();    //识别无符号数并输出
    return 0;
}

void unsigned_number() {
    bool isfirst = true;
    int hh, tt;    //hh表示识别到的无符号实数的第一个数，tt表述最后一个数
    for (int i = 0; i <= cnt; i++) {
        if (isfirst) {    //识别无符号数的第一个数
            if (isdigit(ch[i])) {
                isfirst = false;
                hh = i;    //标记识别到的无符号数的第一个数
            } else continue;
        } else {
            if (isdigit(ch[i])) continue;
            else if (ch[i] == '.') {
                //输出浮点数或整数或浮点数的科学计数表示
                tt = float_number(i);
                cout << "无符号实数：";
                print(hh, tt);
                isfirst = true;
                i = tt;
            } else if (ch[i] == 'E') {
                //输出整数或整数的科学计数表示
                tt = _E(i);
                cout << "无符号实数：";
                print(hh, tt);
                isfirst = true;
                i = tt;
            } else {
                //输出整数
                tt = i;
                cout << "无符号整数：";
                print(hh, tt);
                isfirst = true;
            }
        }
    }
}

void print(int hh, int tt) {
    for (int j = hh; j < tt; j++)
        cout << ch[j];
    cout << endl;
}

int float_number(int i) {
    //设置flag来判断是不是小数点后第一个字符
    bool flag = true;
    int t;
    for (int j = i + 1; j <= cnt; j++) {
        if (flag) {
            flag = false;
            //小数点'.'后第一个字符是数字则继续否则返回'.'的下标
            if (isdigit(ch[j])) continue;
            else {
                t = i;
                return t;
            }
        } else {
            if (isdigit(ch[j])) continue;
                //遇到'E',通过调用函数_E()来得到要返回的下标
            else if (ch[j] == 'E') {
                t = _E(j);
                return t;
            } else {
                t = j;
                return t;
            }
        }
    }
}

int _E(int i) {
    //设置flag来判断是不是'E'后的第一个字符，设置flag2来判断是不是'E'后的第二个字符
    //通过这两个标志来判断字符E之后字符的合法性
    bool flag = true;
    bool flag2 = true;
    int t;
    for (int j = i + 1; j < cnt; j++) {
        if (flag) {
            flag = false;
            //字符'E'之后是'+'或'-'则继续 否则返回字符'E'的下标
            if (ch[j] == '+' || ch[j] == '-') continue;
            else {
                t = i;
                return t;
            }
        } else {
            if (flag2) {
                flag2 = false;
                //如果'E'后面的第二个字符是数字则继续，否则返回'E'的下标
                if (isdigit(ch[j])) continue;
                else {
                    t = i;
                    return t;
                }
            } else {
                if (isdigit(ch[j])) continue;
                else {
                    t = j;
                    return t;
                }
            }
        }
    }
}
