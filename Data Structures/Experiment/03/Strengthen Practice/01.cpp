/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Strengthen_Practice
  * @File           : 01.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 编写递归算法，计算二叉树中叶子结点的数目。
  * @Attention      : None
  * @Date           : 2024/6/22 23:42
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "../../../BinaryTree.hpp"

using namespace std;

int LeafNodeCount(BiTree T);

int main() {
    BiTree T;
    CreateBiTree(T);
    cout << "这棵树叶子结点有" << LeafNodeCount(T) << "个" << endl;
    return 0;
}

int LeafNodeCount(BiTree T) {
    if (T == NULL) {
        return 0;
    } else if (T->lchild == NULL && T->rchild == NULL) {
        return 1;
    } else {
        return LeafNodeCount(T->lchild) + LeafNodeCount(T->rchild);
    }
}
