/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : SqQueue.hpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/22 15:32
  * @Version        : 1.0
  ****************************************************************************************
  */

#ifndef EXPERIMENT_SQQUEUE_HPP
#define EXPERIMENT_SQQUEUE_HPP

//SqQueue.hpp
#include <iostream>
#include "data_structures.hpp"

using namespace std;

#define MAXQSIZE 100
typedef int QElemType;
typedef struct {
    QElemType *base;
    int front;
    int rear;
} SqQueue;

Status InitQueue(SqQueue &Q) {
    Q.base = new QElemType[MAXQSIZE];
    if (!Q.base) {
        exit(OVERFLOW);
    }
    Q.front = Q.rear = 0;
    return OK;
}

Status DestroyQueue(SqQueue &Q) {
    if (Q.base == nullptr) {
        return ERROR;
    }
    delete[] Q.base;
    Q.front = Q.rear = 0;
    return OK;
}

Status ClearQueue(SqQueue &Q) {
    if (Q.base == nullptr) {
        return ERROR;
    }
    Q.front = Q.rear = 0;
    return OK;
}

bool QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

QElemType GetHead(SqQueue Q) {
    if (Q.front == Q.rear) {
        exit(ERROR);
    }
    return Q.base[Q.front];
}

Status EnQueue(SqQueue &Q, QElemType e) {
    if ((Q.rear + 1) % MAXQSIZE == Q.front) {
        return ERROR;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

QElemType DeQueue(SqQueue &Q, QElemType &e) {
    if (Q.front == Q.rear) {
        return ERROR;
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return e;
}

void QueueTraverse(SqQueue Q) {
    if (Q.front == Q.rear) {
        return;
    }
    int i = Q.front;
    while (i != Q.rear) {
        cout << Q.base[i] << " ";
        i = (i + 1) % MAXQSIZE;
    }
    cout << endl;
}
#endif //EXPERIMENT_SQQUEUE_HPP
