/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 05
  * @File           : 01.c
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/24 15:48
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <stdio.h>

typedef struct {
    int a[30];
    int length;
} sqtable;

sqtable st;
int b = 0;
int count = 1;

void createst(int k) {
    int i;
    printf("Please input data:");
    st.a[0] = -100;
    for (i = 1; !b && (i <= k); ++i) {
        scanf("%d", &st.a[i]);
        if (st.a[i] < st.a[i - 1]) {
            printf("Input data error.\n");
            b = 1;
        }
    }
    if (!b) {
        st.length = k;
        printf("The table is built.\n");
    }
}

void stfind(sqtable st, int y) {
    int f, l, h, m;
    l = 1;
    h = st.length;
    f = 1;
    while ((l <= h) && f) {
        m = (l + h) / 2;
        if (st.a[m] == y) {
            f = 0;
        } else if (st.a[m] > y) {
            h = m - 1;
            count++;
        } else {
            l = m + 1;
            count++;
        }
    }
    if (f) {
        printf("Not find %d.\n", y);
    } else {
        printf("Find %d in position %d.\n", y, m);
    }
}

//将折半查找算法改写为递归算法
int stfind2(sqtable st, int y, int l, int h) {
    int m;
    if (l > h) {
        return -1;
    }
    m = (l + h) / 2;
    if (st.a[m] == y) {
        return m;
    } else if (st.a[m] > y) {
        return stfind2(st, y, l, m - 1);
    } else {
        return stfind2(st, y, m + 1, h);
    }
}

int main() {
    int n, x;
    printf("\nPlease input n:");
    scanf("%d", &n);
    createst(n);
    if (!b) {
        printf("Please input you want find value:");
        scanf("%d", &x);
        stfind(st, x);
    }
    printf("The search times is %d.\n", count);
    return 0;
}
