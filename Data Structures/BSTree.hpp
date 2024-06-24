/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : BSTree.hpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/24 17:19
  * @Version        : 1.0
  ****************************************************************************************
  */

#ifndef EXPERIMENT_BSTREE_HPP
#define EXPERIMENT_BSTREE_HPP

#include <iostream>

using namespace std;

typedef int ElemType;
typedef struct BSTNode {
    ElemType data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

void InitBSTree(BSTree &T) {
    T = NULL;
}

void InsertBST(BSTree &T, ElemType e) {
    if (T == NULL) {
        T = new BSTNode;
        T->data = e;
        T->lchild = T->rchild = NULL;
    } else if (e < T->data) {
        InsertBST(T->lchild, e);
    } else if (e > T->data) {
        InsertBST(T->rchild, e);
    }
}

void CreatBST(BSTree &T) {
    T = NULL;
    ElemType e;
    cin >> e;
    while (e != 0) {
        InsertBST(T, e);
        cin >> e;
    }
}

BSTree SearchBST(BSTree T, ElemType e) {
    if (T == NULL || T->data == e) {
        return T;
    } else if (e < T->data) {
        return SearchBST(T->lchild, e);
    } else {
        return SearchBST(T->rchild, e);
    }
}

#endif //EXPERIMENT_BSTREE_HPP
