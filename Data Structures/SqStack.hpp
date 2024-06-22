/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 02
  * @File           : SqStack.hpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/22 10:52
  * @Version        : 1.0
  ****************************************************************************************
  */

#ifndef EXPERIMENT_SQSTACK_HPP
#define EXPERIMENT_SQSTACK_HPP

#include <iostream>
#include "data_structures.hpp"

#define MAXSIZE 100

using namespace std;

typedef int SElemType;
typedef struct {
    SElemType *base;
    SElemType *top;
    int stackSize;
} SqStack;

Status InitStack(SqStack &S) {
    S.base = new SElemType[MAXSIZE];
    if (!S.base) {
        exit(OVERFLOW);
    }
    S.top = S.base;
    S.stackSize = MAXSIZE;
    return OK;
}

Status DestroyStack(SqStack &S) {
    if (S.base == nullptr) {
        return ERROR;
    }
    delete[] S.base;
    S.stackSize = 0;
    return OK;
}

Status ClearStack(SqStack &S) {
    if (S.base == nullptr) {
        return ERROR;
    }
    S.top = S.base;
    return OK;
}

Status StackEmpty(SqStack S) {
    if (S.base == nullptr) {
        return ERROR;
    }
    return S.top == S.base ? OK : ERROR;
}

int StackLength(SqStack S) {
    if (S.base == nullptr) {
        return ERROR;
    }
    return S.top - S.base;
}

SElemType GetTop(SqStack S) {
    if (S.top != S.base) {
        return *(S.top - 1);
    }
    return ERROR;
}

Status Push(SqStack &S, SElemType e) {
    if (S.top - S.base >= S.stackSize) {
        return ERROR;
    }
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, SElemType &e) {
    if (S.top == S.base) {
        return ERROR;
    }
    e = *--S.top;
    return OK;
}

void StackTraverse(SqStack S) {
    if (S.base == nullptr) {
        return;
    }
    for (SElemType *p = S.base; p < S.top; p++) {
        cout << *p << " ";
    }
    cout << endl;
}

#endif //EXPERIMENT_SQSTACK_HPP
