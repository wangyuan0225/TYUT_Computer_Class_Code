/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Strengthen_Practice
  * @File           : 02.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : ��д�ݹ��㷨���ڶ���������λ�����������е�K��λ�õĽ�㡣
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
    cout << "������K��ֵ:";
    cin >> k;
    BiTree p = PreNode(T, k);
    if (p != NULL) {
        cout << "���ֵΪ��" << p->data << endl;
    } else {
        cout << "�����ڴ˽��" << endl;
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
