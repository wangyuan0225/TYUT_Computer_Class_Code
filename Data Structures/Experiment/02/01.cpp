/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 02
  * @File           : 01.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/22 11:05
  * @Version        : 1.0
  ****************************************************************************************
  */

//01.cpp
#include <iostream>
#include "../../SqStack.hpp"

using namespace std;

int main() {
    int choose, flag = 0;
    int num;//进栈个数
    SElemType v, t;
    SqStack S;
    cout << "1.初始化栈" << endl;
    cout << "2.顺序栈进栈" << endl;
    cout << "3.顺序栈出栈" << endl;
    cout << "4.取顺序栈的栈顶元素" << endl;
    cout << "5.遍历顺序栈" << endl;
    cout << "0.退出" << endl;
    choose = -1;
    while (choose != 0) {
        cout << "请输入选项0-5：";
        cin >> choose;
        switch (choose) {
            case 1: {
                if (InitStack(S)) {
                    flag = 1;
                    cout << "初始化成功！" << endl;
                } else {
                    cout << "初始化失败！" << endl;
                }
            }
                break;
            case 2: {
                //如果已完成初始化
                if (flag) {
                    cout << "请输入进栈元素个数:" << endl;
                    cin >> num;
                    cout << "请依次输入进栈元素" << endl;
                    for (int i = 0; i < num; i++) {
                        cin >> v;
                        Push(S, v);
                        cout << v << "  ";
                    }
                    cout << endl;
                    cout << "元素入栈成功!" << endl;
                } else {
                    cout << "栈未创建，请重新输入！" << endl;
                }
            }
                break;
            case 3: {
                cout << "依次出栈元素为：";
                while (Pop(S, t)) {
                    flag = -1;
                    cout << t << " ";
                }
                cout << endl;
            }
                break;
            case 4: {
                if (flag != -1 && flag != 0) {
                    cout << "栈顶元素为：" << GetTop(S) << endl;
                } else {
                    cout << "未初始化或元素已完成出栈，栈内无元素！" << endl;
                }
            }
                break;
            case 5: {
                if (flag != -1 && flag != 0) {
                    cout << "栈内元素为：";
                    StackTraverse(S);
                } else {
                    cout << "未初始化或元素已完成出栈，栈内无元素！" << endl;
                }
            }
                break;
        }
    }
    system("pause");
    return 0;
}
