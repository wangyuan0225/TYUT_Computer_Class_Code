/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : 02.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 通过一趟遍历，确定长度为n的单链表中值最大的元素并输出。
  * @Attention      : None
  * @Date           : 2024/5/26 17:02
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "../../../LinkList.hpp"

using namespace std;

int main() {
    int n;
    cin >> n;
    int max = INT_MIN;
    LinkList L;
    InitList(L);
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        ListInsert(L, i, temp);
    }
    for (int i = 1; i <= n; ++i) {
        int temp;
        GetElem(L, i, temp);
        if (temp > max) {
            max = temp;
        }
    }
    cout << max << endl;
    return 0;
}
