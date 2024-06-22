/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : main.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/22 11:05
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "../../SqStack.hpp"

using namespace std;

int main() {
    SqStack s;
    InitStack(s);
    SElemType e;
    for (int i = 0; i < 10; ++i) {
        Push(s, i);
    }
    StackTraverse(s);
    cout << GetTop(s) << endl;
    while (!StackEmpty(s)) {
        Pop(s, e);
        cout << e << " ";
    }


    return 0;
}
