/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : BinaryTree.hpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/22 22:06
  * @Version        : 1.0
  ****************************************************************************************
  */

#ifndef EXPERIMENT_BINARYTREE_HPP
#define EXPERIMENT_BINARYTREE_HPP

#include <iostream>
#include "data_structures.hpp"

using namespace std;

typedef char TElemType;

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct QNode {
    BiTree data;
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

Status EnQueue(LinkQueue &Q, BiTree e) {
    QueuePtr p = new QNode;
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, BiTree &e) {
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

bool QueueEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

Status InitBiTree(BiTree &T) {
    T = nullptr;
    return OK;
}

Status DeleteBiTree(BiTree &T) {
    if (T) {
        DeleteBiTree(T->lchild);
        DeleteBiTree(T->rchild);
        free(T);
    }
    return OK;
}

Status CreateBiTree(BiTree &T) {
    TElemType ch;
    cin >> ch;
    if (ch == '#') {
        T = nullptr;
    } else {
        T = (BiTree) malloc(sizeof(BiTNode));
        if (!T) {
            exit(OVERFLOW);
        }
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

Status ClearBiTree(BiTree &T) {
    if (T) {
        ClearBiTree(T->lchild);
        ClearBiTree(T->rchild);
        free(T);
        T = nullptr;
    }
    return OK;
}

bool BiTreeEmpty(BiTree T) {
    if (T) {
        return false;
    } else {
        return true;
    }
}

int BiTreeDepth(BiTree T) {
    if (!T) {
        return 0;
    }
    int l = BiTreeDepth(T->lchild);
    int r = BiTreeDepth(T->rchild);
    return l > r ? l + 1 : r + 1;
}

TElemType Root(BiTree T) {
    if (BiTreeEmpty(T)) {
        return '#';
    } else {
        return T->data;
    }
}

TElemType Value(BiTree T, BiTree e) {
    return e->data;
}

Status Assign(BiTree T, BiTree e, TElemType value) {
    e->data = value;
    return OK;
}

BiTree Parent(BiTree T, BiTree e) {
    if (T) {
        if (T->lchild == e || T->rchild == e) {
            return T;
        }
        BiTree p;
        if (p = Parent(T->lchild, e)) {
            return p;
        }
        if (p = Parent(T->rchild, e)) {
            return p;
        }
    }
    return nullptr;
}

BiTree LeftChild(BiTree T, BiTree e) {
    return e->lchild;
}

BiTree RightChild(BiTree T, BiTree e) {
    return e->rchild;
}

BiTree LeftSibling(BiTree T, BiTree e) {
    BiTree p;
    if (p = Parent(T, e)) {
        if (p->lchild == e) {
            return nullptr;
        } else {
            return p->lchild;
        }
    }
    return nullptr;
}

BiTree RightSibling(BiTree T, BiTree e) {
    BiTree p;
    if (p = Parent(T, e)) {
        if (p->rchild == e) {
            return nullptr;
        } else {
            return p->rchild;
        }
    }
    return nullptr;
}

Status InsertChild(BiTree T, BiTree p, int LR, BiTree c) {
    if (LR == 0) {
        c->rchild = p->lchild;
        p->lchild = c;
    } else if (LR == 1) {
        c->rchild = p->rchild;
        p->rchild = c;
    }
    return OK;
}

Status DeleteChild(BiTree T, BiTree p, int LR) {
    if (LR == 0) {
        ClearBiTree(p->lchild);
    } else if (LR == 1) {
        ClearBiTree(p->rchild);
    }
    return OK;
}

void PreOrderTraverse(BiTree T) {
    if (T == nullptr) {
        return;
    }
    cout << T->data << " ";
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T) {
    if (T == nullptr) {
        return;
    }
    InOrderTraverse(T->lchild);
    cout << T->data << " ";
    InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T) {
    if (T == nullptr) {
        return;
    }
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    cout << T->data << " ";
}

void LevelOrderTraverse(BiTree T) {
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
    while (!QueueEmpty(Q)) {
        DeQueue(Q, p);
        cout << p->data << " ";
        if (p->lchild) {
            EnQueue(Q, p->lchild);
        }
        if (p->rchild) {
            EnQueue(Q, p->rchild);
        }
    }
}

int NodeCount(BiTree T) {
    if (T == nullptr) {
        return 0;
    }
    return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

#endif //EXPERIMENT_BINARYTREE_HPP
