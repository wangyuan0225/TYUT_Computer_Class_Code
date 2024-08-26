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
    printf("先序构造一棵二叉树(左/右孩子为空用'#'表示):");
    BiTree T;
    CreateBiTree(T);
    printf("此二叉树的先序遍历序列是:");
    PreOrderTraverse(T);
    printf("\n");
    printf("此二叉树的中序遍历序列是:");
    InOrderTraverse(T);
    printf("\n");
    printf("此二叉树的后序遍历序列是:");
    PostOrderTraverse(T);
    printf("\n");
    printf("这棵树结点有%d个\n", NodeCount(T));
    printf("这棵树的深度为:%d\n", BiTreeDepth(T));
    system("pause");
    return 0;
}
