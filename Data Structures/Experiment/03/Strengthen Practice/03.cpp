/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Strengthen_Practice
  * @File           : 03.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/23 11:38
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "../../../data_structures.hpp"

using namespace std;

typedef char TElemType;

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef BiTree ElemType;

typedef struct QNode {
    BiTree data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

Status InitStack(LinkStack &S) {
    S = nullptr;
    return OK;
}

ElemType GetTop(LinkStack S, ElemType &e) {
    if (S == nullptr) {
        return ERROR;
    }
    e = S->data;
    return e;
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

Status InitBiTree(BiTree &T) {
    T = nullptr;
    return OK;
}

Status CreateBiTree(BiTree &T) {
    TElemType ch;
    cin >> ch;
    if (ch == '#') {
        T = nullptr;
    } else {
        T = new BiTNode;
        if (!T) {
            exit(OVERFLOW);
        }
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

void PreOrderTraverse(BiTree T) {
    LinkStack S;
    InitStack(S);
    BiTree p = T;
    BiTNode *q = new BiTNode;
    while (p || S) {
        if (p) {
            cout << p->data << " ";
            Push(S, p);
            p = p->lchild;
        } else {
            Pop(S, q);
            p = q->rchild;
        }
    }
}

void InOrderTraverse(BiTree T) {
    LinkStack S;
    InitStack(S);
    BiTree p = T;
    BiTNode *q = new BiTNode;
    while (p || S) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        } else {
            Pop(S, q);
            cout << q->data << " ";
            p = q->rchild;
        }
    }
}

void PostOrderTraverse(BiTree T) {
    LinkStack S;
    InitStack(S);
    BiTree p = T;
    BiTNode *q = new BiTNode;
    BiTree r = nullptr;
    while (p || S) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        } else {
            GetTop(S, q);
            if (q->rchild && q->rchild != r) {
                p = q->rchild;
            } else {
                Pop(S, q);
                cout << q->data << " ";
                r = q;
            }
        }
    }
}

int main() {
    BiTree T;
    InitBiTree(T);
    CreateBiTree(T);
    cout << "先序遍历：" << endl;
    PreOrderTraverse(T);
    cout << endl;
    cout << "中序遍历：" << endl;
    InOrderTraverse(T);
    cout << endl;
    cout << "后序遍历：" << endl;
    PostOrderTraverse(T);
    cout << endl;
    return 0;
}
