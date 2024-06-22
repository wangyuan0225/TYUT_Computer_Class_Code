/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Strengthen_Practice
  * @File           : LinkList.hpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/5/10 10:38
  * @Version        : 1.0
  ****************************************************************************************
  */

#ifndef DATA_STRUCTURES_LINKLIST_HPP
#define DATA_STRUCTURES_LINKLIST_HPP

#include <iostream>
#include "data_structures.hpp"

using namespace std;

typedef int ElemType;

//单链表的存储结构
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

Status InitList(LinkList &L) {
    L = new LNode;
    L->next = nullptr;
    return OK;
}

Status DestroyList(LinkList &L) {
    if (L == nullptr) {
        return ERROR;
    }
    LinkList p;
    while (L) {
        p = L;
        L = L->next;
        delete p;
    }
    return OK;
}

Status ClearList(LinkList &L) {
    if (L == nullptr) {
        return ERROR;
    }
    LinkList p, q;
    p = L->next;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = nullptr;
    return OK;
}

bool ListEmpty(LinkList L) {
    if (L->next == nullptr) {
        return true;
    }
    return false;
}

int ListLength(LinkList L) {
    if (L == nullptr) {
        return 0;
    }
    int i = 0;
    LinkList p = L->next;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType &e) {
    if (L == nullptr) {
        return ERROR;
    }
    LinkList p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return ERROR;
    }
    e = p->data;
    return OK;
}

int LocateElem(LinkList L, ElemType e) {
    if (L == nullptr) {
        return 0;
    }
    LinkList p = L->next;
    int i = 1;
    while (p && p->data != e) {
        p = p->next;
        ++i;
    }
    if (p) {
        return i;
    } else {
        return 0;
    }
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e) {
    if (L == nullptr) {
        return ERROR;
    }
    LinkList p = L->next;
    LinkList q = L;
    while (p && p->data != cur_e) {
        q = p;
        p = p->next;
    }
    if (!p || p == L->next) {
        return ERROR;
    }
    pre_e = q->data;
    return OK;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e) {
    if (L == nullptr) {
        return ERROR;
    }
    LinkList p = L->next;
    while (p && p->data != cur_e) {
        p = p->next;
    }
    if (!p || !p->next) {
        return ERROR;
    }
    next_e = p->next->data;
    return OK;
}

Status ListInsert(LinkList &L, int i, ElemType e) {
    if (L == nullptr) {
        return ERROR;
    }
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) {
        return ERROR;
    }
    LinkList s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList &L, int i) {
    if (L == nullptr) {
        return ERROR;
    }
    LinkList p = L;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p->next || j > i - 1) {
        return ERROR;
    }
    LinkList q = p->next;
    p->next = q->next;
    delete q;
    return OK;
}

void TraverseList(LinkList L) {
    if (L == nullptr) {
        return;
    }
    LinkList p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

#endif //DATA_STRUCTURES_LINKLIST_HPP
