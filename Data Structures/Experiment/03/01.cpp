/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : 01.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/22 22:55
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "../../BinaryTree.hpp"

using namespace std;

int main() {
    printf("������һ�ö�����(��/�Һ���Ϊ����'#'��ʾ):");
    BiTree T;
    CreateBiTree(T);
    printf("�˶��������������������:");
    PreOrderTraverse(T);
    printf("\n");
    printf("�˶��������������������:");
    InOrderTraverse(T);
    printf("\n");
    printf("�˶������ĺ������������:");
    PostOrderTraverse(T);
    printf("\n");
    printf("����������%d��\n", NodeCount(T));
    printf("����������Ϊ:%d\n", BiTreeDepth(T));
    system("pause");
    return 0;
}
