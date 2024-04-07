/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Data_Structures
  * @File           : SqList.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 线性表——顺序表
  * @Attention      : None
  * @Date           : 2024/4/1 20:59
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "data_structures.h"

using namespace std;

const int MAXSIZE = 100;

// 暂时以 int 型替代 ElemType
typedef int ElemType;

struct SqList {
    ElemType *elem;
    int length;
};

/**
 * 构造一个空的线性表 L
 * @param L
 * @return 状态
 */
Status InitList(SqList &L);

Status DestroyList(SqList &L);

Status ClearList(SqList &L);

bool ListEmpty(SqList L);

int ListLength(SqList L);

Status GetElem(SqList L, int i, ElemType &e);

int LocateElem(SqList L, ElemType e);

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e);

Status ListInsert(SqList &L, int i, ElemType e);

Status ListDelete(SqList &L, int i);

void TraverseList(SqList L);

int main() {

    return 0;
}

Status InitList(SqList &L) {
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem) {
        exit(OVERFLOW);
    }
    L.length = 0;
    return OK;
}

Status DestroyList(SqList &L) {
    if (L.elem == nullptr) {
        return ERROR;
    }
    delete[] L.elem;
    L.length = 0;
    return OK;
}

Status ClearList(SqList &L) {
    if (L.elem == nullptr) {
        return ERROR;
    }
    DestroyList(L);
    InitList(L);
    return OK;
}

bool ListEmpty(SqList L) {
    if (L.elem == nullptr) {
        return false;
    }
    if (L.length == 0) {
        return true;
    }
    return false;
}

int ListLength(SqList L) {
    if (L.elem == nullptr) {
        return 0;
    }
    return L.length;
}

Status GetElem(SqList L, int i, ElemType &e) {
    if (L.elem == nullptr) {
        return ERROR;
    }
    if (i < 1 || i > ListLength(L)) {
        return ERROR;
    }
    e = L.elem[i - 1];
    return OK;
}

int LocateElem(SqList L, ElemType e) {
    if (L.elem == nullptr) {
        return 0;
    }
    for (int i = 0; i < L.length; ++i) {
        if (L.elem[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e) {
    pre_e = -1;
//    pre_e = nullptr;
    if (L.elem == nullptr) {
        return ERROR;
    }
    for (int i = 1; i < L.length; ++i) {
        if (L.elem[i] == cur_e) {
            pre_e = L.elem[i - 1];
            return OK;
        }
    }
    return ERROR;
}

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e) {
    next_e = -1;
    if (L.elem == nullptr) {
        return ERROR;
    }
    for (int i = 0; i < L.length - 1; ++i) {
        if (L.elem[i] == cur_e) {
            next_e = L.elem[i + 1];
            return OK;
        }
    }
    return ERROR;
}

Status ListInsert(SqList &L, int i, ElemType e) {
    if (L.elem == nullptr) {
        return ERROR;
    }
    if (i < 1 || i > L.length + 1) {
        return ERROR;
    }
    if (L.length >= MAXSIZE) {
        return ERROR;
    }
    for (int j = L.length; j >= i; --j) {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i - 1] = e;
    ++L.length;
    return OK;
}

Status ListDelete(SqList &L, int i) {
    if (L.elem == nullptr) {
        return ERROR;
    }
    if (i < 1 || i > L.length) {
        return ERROR;
    }
    for (int j = i; j < L.length; ++j) {
        L.elem[j - 1] = L.elem[j];
    }
    --L.length;
    return OK;
}

void TraverseList(SqList L) {
    if (L.elem == nullptr) {
        return;
    }
    for (int i = 0; i < L.length; ++i) {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}