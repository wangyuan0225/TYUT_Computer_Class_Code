/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : LinkStack.hpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/22 11:27
  * @Version        : 1.0
  ****************************************************************************************
  */

#ifndef EXPERIMENT_LINKSTACK_HPP
#define EXPERIMENT_LINKSTACK_HPP

#include <iostream>
#include "data_structures.hpp"

using namespace std;

typedef int ElemType;
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

Status InitStack(LinkStack &S) {
    S = nullptr;
    return OK;
}

Status DestroyStack(LinkStack &S) {
    if (S == nullptr) {
        return ERROR;
    }
    StackNode *p;
    while (S) {
        p = S;
        S = S->next;
        delete p;
    }
    return OK;
}

Status ClearStack(LinkStack &S) {
    DestroyStack(S);
    S = nullptr;
    return OK;
}

bool StackEmpty(LinkStack S) {
    return S == nullptr;
}

int StackLength(LinkStack S) {
    if (S == nullptr) {
        return ERROR;
    }
    StackNode *p = S;
    int length = 0;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

ElemType GetTop(LinkStack S) {
    if (S != nullptr) {
        return S->data;
    }
    return ERROR;
}

Status Push(LinkStack &S, ElemType e) {
    StackNode *p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}

Status Pop(LinkStack &S, ElemType &e) {
    if (S == nullptr) {
        return ERROR;
    }
    StackNode *p = S;
    e = S->data;
    S = S->next;
    delete p;
    return OK;
}

void StackTraverse(LinkStack S) {
    if (S == nullptr) {
        return;
    }
    else {
        StackTraverse(S->next);
        cout << S->data << " ";
    }
}

#endif //EXPERIMENT_LINKSTACK_HPP
