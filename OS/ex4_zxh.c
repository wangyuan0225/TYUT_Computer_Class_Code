/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : OS
  * @File           : ex4_zxh.c
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/11/14 16:24
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <stdio.h>

#define PG 7
#define FM 4

typedef struct PT {
    int pr;
    int fn;
    int m;
    int dl;
} PT;

void initializePageTable(PT pt[]) {
    pt[0] = (PT) {1, 5, 0, 11};
    pt[1] = (PT) {1, 8, 0, 12};
    pt[2] = (PT) {1, 9, 0, 13};
    pt[3] = (PT) {1, 1, 0, 21};
    pt[4] = (PT) {0, 0, 0, 22};
    pt[5] = (PT) {0, 0, 0, 23};
    pt[6] = (PT) {0, 0, 0, 121};
}

void fifo(PT pt[], int m, int pages[], int n) {
    int P[PG];
    int k = 0;
    for (int i = 0; i < m; i++) {
        P[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;
        for (int j = 0; j < m; j++) {
            if (P[j] == page) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("OUT %d\n", P[k]);
            printf("IN %d\n", page);
            P[k] = page;
            k = (k + 1) % m;
            pt[page].pr = 1;
            pt[page].fn = P[k];
        }
    }
}

int main() {
    PT pageTable[PG];
    initializePageTable(pageTable);
    int pages[12] = {0, 1, 2, 3, 0, 4, 5, 1, 2, 0, 6, 6};
    int m = FM;
    fifo(pageTable, m, pages, 12);
    return 0;
}
