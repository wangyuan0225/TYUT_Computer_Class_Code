/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 05
  * @File           : 03.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/24 18:05
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;
#define MAXSIZE 20
typedef struct {
    int key;
    char *otherinfo;
} ElemType;

typedef struct {
    ElemType *r;
    int length;
} SqList;

int Partition(SqList &L, int low, int high) {
    int pivotkey = L.r[low].key;
    L.r[0] = L.r[low];
    while (low < high) {
        while (low < high && L.r[high].key >= pivotkey) {
            high--;
        }
        L.r[low] = L.r[high];
        while (low < high && L.r[low].key <= pivotkey) {
            low++;
        }
        L.r[high] = L.r[low];
    }
    L.r[low].key = pivotkey;
    return low;
}

void QSort(SqList &L, int low, int high) {
    int pivotloc;
    if (low < high) {
        pivotloc = Partition(L, low, high);
        QSort(L, low, pivotloc - 1);
        QSort(L, pivotloc + 1, high);
    }
}

void QuickSort(SqList &L) {
    QSort(L, 1, L.length);
}

void Create_Sq(SqList &L) {
    int i, n;
    cout << "请输入数据个数，不超过" << MAXSIZE << "个" << endl;
    cin >> n;
    cout << "请输入待排序的数据" << endl;
    while (n > MAXSIZE) {
        cout << "输入数据个数超过" << MAXSIZE << "个，请重新输入" << endl;
        cin >> n;
    }

    for (i = 1; i <= n; i++) {
        cin >> L.r[i].key;
        L.length++;
    }
}

void show(SqList L) {
    for (int i = 1; i <= L.length; i++) {
        cout << L.r[i].key << " ";
    }
    cout << endl;
}

int main() {
    SqList L;
    L.r = new ElemType[MAXSIZE];
    L.length = 0;
    Create_Sq(L);
    QuickSort(L);
    cout << "排序后的结果为：" << endl;
    show(L);
    return 0;
}
