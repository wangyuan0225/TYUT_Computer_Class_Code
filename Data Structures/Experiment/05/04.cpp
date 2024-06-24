/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 05
  * @File           : 04.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 给定关键字序列{23,11,32,55,90,78,5,8,66,88}，请用下列方法进行排序。
  *                     冒泡排序和简单选择排序
  * @Attention      : None
  * @Date           : 2024/6/24 18:16
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

void BubbleSort(int a[], int n) {
    int m = n - 1, flag = 1;
    while (m > 0 && flag) {
        flag = 0;
        for (int j = 0; j < m; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        m--;
    }
}

void SelectSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(a[i], a[min]);
        }
    }
}

int main() {
    int a[] = {23, 11, 32, 55, 90, 78, 5, 8, 66, 88};
    int n = sizeof(a) / sizeof(a[0]);
    BubbleSort(a, n);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    SelectSort(a, n);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
