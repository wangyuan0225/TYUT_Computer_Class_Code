/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Data_Structures
  * @File           : 01.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/5/10 9:31
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "SqList.hpp"

using namespace std;

int main() {
    SqList La, Lb, Lc;
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
//    TraverseList(La);
//    TraverseList(Lb);
    Lc.length = La.length + Lb.length;
    Lc.elem = new ElemType[Lc.length];
    ElemType *pa = La.elem, *pb = Lb.elem, *pc = Lc.elem,
            *pa_last = La.elem + La.length - 1,
            *pb_last = Lb.elem + Lb.length - 1;

    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }
    while (pa <= pa_last) {
        *pc++ = *pa++;
    }
    while (pb <= pb_last) {
        *pc++ = *pb++;
    }
    TraverseList(Lc);
    return 0;
}
