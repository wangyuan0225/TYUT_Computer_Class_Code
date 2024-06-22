/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Reflective_Exercise
  * @File           : 03.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 设数组 a={11, 33, 44, 68, 77}，数组 b={22, 33, 77, 88，99}，两个数组均为链式存储，编程完成下列题目。
                        （1）求a和b的并集, 统计并集中元素的个数。
                        （2）求a和b的交集, 统计交集中元素的个数。
                        （3）在数组a中插入55，保持数组a有序。
                        （4）在数组b中删除元素77。
  * @Attention      : None
  * @Date           : 2024/5/26 19:47
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "../../../LinkList.hpp"

using namespace std;

int main() {
    int a1[] = {11, 33, 44, 68, 77};
    int b1[] = {22, 33, 77, 88, 99};
    LinkList a, b;
    InitList(a);
    InitList(b);
    for (int i = 0; i < 5; ++i) {
        ListInsert(a, i + 1, a1[i]);
        ListInsert(b, i + 1, b1[i]);
    }
    // 求a和b的并集, 统计并集中元素的个数。
    LinkList c;
    InitList(c);
    int i = 1, j = 1;
    while (i <= ListLength(a) && j <= ListLength(b)) {
        int ai, bj;
        GetElem(a, i, ai);
        GetElem(b, j, bj);
        if (ai < bj) {
            ListInsert(c, ListLength(c) + 1, ai);
            i++;
        } else if (ai > bj) {
            ListInsert(c, ListLength(c) + 1, bj);
            j++;
        } else {
            ListInsert(c, ListLength(c) + 1, ai);
            i++;
            j++;
        }
    }
    while (i <= ListLength(a)) {
        int ai;
        GetElem(a, i, ai);
        ListInsert(c, ListLength(c) + 1, ai);
        i++;
    }
    while (j <= ListLength(b)) {
        int bj;
        GetElem(b, j, bj);
        ListInsert(c, ListLength(c) + 1, bj);
        j++;
    }
    TraverseList(c);

    // 求a和b的交集, 统计交集中元素的个数。
    ClearList(c);
    i = 1, j = 1;
    while (i <= ListLength(a) && j <= ListLength(b)) {
        int ai, bj;
        GetElem(a, i, ai);
        GetElem(b, j, bj);
        if (ai < bj) {
            i++;
        } else if (ai > bj) {
            j++;
        } else {
            ListInsert(c, ListLength(c) + 1, ai);
            i++;
            j++;
        }
    }
    TraverseList(c);

    // 在数组a中插入55，保持数组a有序。
    for (i = 1; i <= ListLength(a); ++i) {
        int ai;
        GetElem(a, i, ai);
        if (ai >= 55) {
            ListInsert(a, i, 55);
            break;
        }
    }
    if (i > ListLength(a)) {
        ListInsert(a, i, 55);
    }
    TraverseList(a);

    // 在数组b中删除元素77。
    for (i = 1; i <= ListLength(b); ++i) {
        int bj;
        GetElem(b, i, bj);
        if (bj == 77) {
            ListDelete(b, i);
            break;
        }
    }
    TraverseList(b);
    return 0;
}
