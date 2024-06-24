/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Strengthen_Practice
  * @File           : 01.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : ��д�ݹ��㷨�������������Ҷ�ӽ�����Ŀ��
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
    cout << "�����Ҷ�ӽ����" << LeafNodeCount(T) << "��" << endl;
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
