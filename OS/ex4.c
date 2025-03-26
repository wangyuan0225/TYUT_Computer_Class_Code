/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : OS
  * @File           : ex4.c
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/11/14 15:24
  * @Version        : 1.0
  ****************************************************************************************
  */

#include "stdio.h"

#define size 1024

struct plist {
    int number;
    int flag;
    int block;
    int modify;
    int location;
};

struct plist p1[7] = {
        {0, 1, 5,  0, 011},
        {1, 1, 8,  0, 012},
        {2, 1, 9,  0, 013},
        {3, 1, 1,  0, 021},
        {4, 0, -1, 0, 022},
        {5, 0, -1, 0, 023},
        {6, 0, -1, 0, 121}};

struct ilist {
    char operation[10];
    int pagenumber;
    int address;
};

struct ilist p2[12] = {{"+",    0, 70},
                       {"+",    1, 50},
                       {"*",    2, 15},
                       {"存",   3, 21},
                       {"取",   0, 56},
                       {"-",    6, 40},
                       {"移位", 4, 53},
                       {"+",    5, 23},
                       {"存",   1, 37},
                       {"取",   2, 78},
                       {"+",    4, 1},
                       {"存",   6, 84}};

int main() {
    int i, lpage, pflage, replacedpage, pmodify;
    int p[4] = {0, 1, 2, 3};
    int k = 0;
    int m = 4;
    long memaddress;
    printf("\n 操作\t 页号 \t页内地址   标志  绝对地址   修改页号   页架号  绝对地址\n");
    for (i = 0; i < 12; i++) {
        lpage = p2[i].pagenumber;
        pflage = p1[lpage].flag;
        if (pflage == 0) {
            replacedpage = p[k];
            pmodify = p1[replacedpage].modify;
            p[k] = lpage;
            k = (k + 1) % m;
            p1[lpage].flag = 1;
            /*此处作用：将标志位改为a1*/
            p1[lpage].block = p1[replacedpage].block;
            p1[replacedpage].block = -1;
            p1[replacedpage].flag = 0;
            p1[replacedpage].modify = 0;
        }
        memaddress = p1[lpage].block * size + p2[i].address;
        if (p2[i].operation == "save")
            p1[lpage].modify = 1;
        printf(" %s\t", p2[i].operation);
        printf("  %d\t", p2[i].pagenumber);
        printf("   %d\t", p2[i].address);
        printf("     %d\t", pflage);
        if (pflage == 1)
            printf("   %d\t", memaddress);
        else
            printf("   *%d\t", p2[i].pagenumber);
        if (pflage == 1)
            printf("        \t");
        else
            printf("    %d->%d\t", p2[i].pagenumber, replacedpage);
        printf("  %d\t", p1[lpage].block);
        printf("  %d\t", memaddress);
        printf("\n");
    }
}