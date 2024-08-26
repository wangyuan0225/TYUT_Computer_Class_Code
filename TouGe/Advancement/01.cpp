/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Advancement
  * @File           : 01.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 输入一个整数num, 30 个人在一条船上，超载，需要 15 人下船。于是人们排成一队，排队的
  *                     位置即为他们的编号。报数，从 1 开始，数到 num 的人下船。如此循环，直到船上仅剩 15
  *                     人为止，问都有哪些编号的人下船了呢？输出下船人的数组。
  * @Attention      : 输出下船人的数组
  * @Date           : 2024/6/28 10:51
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    int arr[30] = {0};
    vector<int> offBoat;
    int count = 0;
    int index = 0;
    int i = 0;
    while (count < 15) {
        if (arr[i] == 0) {
            index++;
        }
        if (index == num) {
            arr[i] = 1;
            offBoat.push_back(i + 1);
            index = 0;
            count++;
        }
        i++;
        if (i == 30) {
            i = 0;
        }
    }
    cout << "[";
    for (int j = 0; j < offBoat.size(); ++j) {
        if (j == offBoat.size() - 1)
            cout << offBoat[j];
        else
            cout << offBoat[j] << ", ";
    }
    cout << "]";
    return 0;
}
