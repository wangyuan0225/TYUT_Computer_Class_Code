/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 04
  * @File           : 01_LinnerList.c
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/5/10 8:12
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
typedef int Status;
typedef int ElemType;

//顺序表的存储结构
typedef struct {
    ElemType *elem;
    int length;
} SqList;

//初始化
Status InitList(SqList *L) {
    L->elem = (ElemType *) malloc(MAXSIZE * sizeof(ElemType));
    if (!L->elem)exit(OVERFLOW);
    L->length = 0;
    return OK;
}

//取值
Status GetElem(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) return ERROR;
    *e = L->elem[i - 1];
    return OK;
}

//查找
int LocateElem(SqList *L, ElemType e) {
    int i;
    for (i = 0; i < L->length; i++)
        if (L->elem[i] == e) return i + 1;
    return 0;
}

//插入
Status ListInsert(SqList *L, int i, ElemType e) {
    int j;
    if (i < 1 || i > L->length + 1) return ERROR;
    if (L->length == MAXSIZE) return ERROR;
    for (j = L->length - 1; j >= i - 1; j--)
        L->elem[j + 1] = L->elem[j];
    L->elem[i - 1] = e;
    ++L->length;
    return OK;
}

//删除
Status ListDelete(SqList *L, int i) {
    int j;
    if ((i < 1) || (i > L->length)) return ERROR;
    for (j = i; j <= L->length - 1; j++)
        L->elem[j - 1] = L->elem[j];
    --L->length;
    return OK;
}

//测试
int main() {
    int num, temp, i, choose, weizhi;
    ElemType e;
    SqList sxb;
    printf("最多存储100个整型元素，请输入元素的个数：\n");
    scanf("%d", &num);
    temp = InitList(&sxb);
    if (temp == OK) {
        for (i = 0; i < num; i++) {
            printf("请输入第%d个元素:", i + 1);
            scanf("%d", &sxb.elem[i]);
            sxb.length++;
        }
    } else printf("顺序表创建失败。");
    printf("操作序号如下：\n1：取值\n2：查找\n3：插入\n4：删除\n5：遍历\n0：退出\n");
    choose = -1;
    while (choose != 0) {
        printf("请输入操作序号：\n");
        scanf("%d", &choose);
        switch (choose) {
            case 1:
                printf("请输入取值位置：\n");
                scanf("%d", &weizhi);
                temp = GetElem(&sxb, weizhi, &e);
                if (temp == OK)
                    printf("第%d个位置的元素是%d。\n", weizhi, e);
                else
                    printf("取值失败。\n");
                break;
            case 2:
                printf("请输入要查找的元素：\n");
                scanf("%d", &e);
                temp = LocateElem(&sxb, e);
                if (temp != ERROR)
                    printf("查找成功，%d是顺序表中的第%d个元素。\n", e, temp);
                else
                    printf("查找失败。\n");
                break;
            case 3:
                printf("请输入要插入的位置：\n");
                scanf("%d", &weizhi);
                printf("请输入要插入的元素：\n");
                scanf("%d", &e);
                temp = ListInsert(&sxb, weizhi, e);
                if (temp == OK)
                    printf("插入成功。\n");
                else
                    printf("插入失败。\n");
                break;
            case 4:
                printf("请输入要删除的位置：\n");
                scanf("%d", &weizhi);
                temp = ListDelete(&sxb, weizhi);
                if (temp == OK)
                    printf("删除成功。\n");
                else
                    printf("删除失败。\n");
                break;
            case 5:
                printf("当前顺序表为：\n");
                for (i = 0; i < sxb.length; i++)
                    printf("第%d个元素：%d\n", i + 1, sxb.elem[i]);

                break;
        }
    }


    return 0;
}
