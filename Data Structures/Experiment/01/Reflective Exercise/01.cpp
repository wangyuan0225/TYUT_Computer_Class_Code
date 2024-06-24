/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Strengthen_Practice
  * @File           : 01.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 正序建立单链表，并打印输出该单链表。
  * @Attention      : None
  * @Date           : 2024/5/26 16:46
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "../../../LinkList.hpp"

using namespace std;

int main() {
    LinkList L;
    InitList(L);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        ListInsert(L, i, temp);
    }
    TraverseList(L);
    return 0;
}
