/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : LinkQueue.hpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/22 19:39
  * @Version        : 1.0
  ****************************************************************************************
  */

#ifndef EXPERIMENT_LINKQUEUE_HPP
#define EXPERIMENT_LINKQUEUE_HPP

//LinkQueue.hpp
#include <iostream>
#include "data_structures.hpp"

using namespace std;
typedef int ElemType;

typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = new QNode;
    Q.front->next = nullptr;
    return OK;
}

Status DestroyQueue(LinkQueue &Q) {
    if (Q.front == nullptr) {
        return ERROR;
    }
    while (Q.front) {
        Q.rear = Q.front->next;
        delete Q.front;
        Q.front = Q.rear;
    }
    return OK;
}

Status ClearQueue(LinkQueue &Q) {
    if (Q.front == nullptr) {
        return ERROR;
    }
    QueuePtr p, q;
    p = Q.front->next;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
    Q.rear = Q.front;
    Q.front->next = nullptr;
    return OK;
}

bool QueueEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

int QueueLength(LinkQueue Q) {
    QueuePtr p = Q.front->next;
    int length = 0;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

ElemType GetHead(LinkQueue Q, ElemType &e) {
    if (Q.front == Q.rear) {
        return ERROR;
    }
    e = Q.front->next->data;
    return e;
}

Status EnQueue(LinkQueue &Q, ElemType e) {
    QueuePtr p = new QNode;
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, ElemType &e) {
    if (Q.front == Q.rear) {
        return ERROR;
    }
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    delete p;
    return OK;
}

void QueueTraverse(LinkQueue Q) {
    QueuePtr p = Q.front->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

#endif //EXPERIMENT_LINKQUEUE_HPP
