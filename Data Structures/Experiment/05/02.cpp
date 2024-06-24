/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 05
  * @File           : 02.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/24 17:09
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "../../BSTree.hpp"

using namespace std;

int main() {
    BSTree T;
    InitBSTree(T);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        InsertBST(T, temp);
    }
    cin >> m;
    SearchBST(T, m)==NULL?cout<<"No":cout<<"Yes";
    return 0;

}
