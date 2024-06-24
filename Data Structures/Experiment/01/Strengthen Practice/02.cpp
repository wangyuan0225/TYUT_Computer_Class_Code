/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Strengthen_Practice
  * @File           : 02.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/5/10 10:46
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "../../../LinkList.hpp"

using namespace std;

int main() {
    LinkList La, Lb, Lc;
    InitList(La);
    InitList(Lb);
    InitList(Lc);
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; ++i) {
        int temp;
        cin >> temp;
        ListInsert(La, i + 1, temp);
    }
    for (int i = 0; i < b; ++i) {
        int temp;
        cin >> temp;
        ListInsert(Lb, i + 1, temp);
    }
    LNode *pa = La->next, *pb = Lb->next;
    Lc = La;
    LNode *pc = Lc;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    TraverseList(Lc);
    DestroyList(Lc); // 注意这里只删除链表 C 即可，因为 C 包含了 A B 中的所有元素了，否则会导致重复删除而无法正常退出
    return 0;
}
