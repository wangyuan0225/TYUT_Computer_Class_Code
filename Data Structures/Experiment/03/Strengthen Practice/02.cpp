/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Strengthen_Practice
  * @File           : 02.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 编写递归算法，在二叉树中求位于先序序列中第K个位置的结点。
  * @Attention      : None
  * @Date           : 2024/6/22 23:55
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "../../../BinaryTree.hpp"

using namespace std;

BiTree PreNode(BiTree T, int &k);

int main() {
    BiTree T;
    CreateBiTree(T);
    int k, j;
    cout << "请输入K的值:";
    cin >> k;
    BiTree p = PreNode(T, k);
    if (p != NULL) {
        cout << "结点值为：" << p->data << endl;
    } else {
        cout << "不存在此结点" << endl;
    }
    return 0;
}

BiTree PreNode(BiTree T, int &k) {
    if (T == NULL || k < 1) {
        return NULL;
    }
    if (k == 1) {
        return T;
    }
    k--;
    BiTree p = PreNode(T->lchild, k);
    if (p == NULL) {
        p = PreNode(T->rchild, k);
    }
    return p;
}
