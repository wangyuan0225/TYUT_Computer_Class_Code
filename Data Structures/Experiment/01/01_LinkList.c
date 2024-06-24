/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : 01_LinkList.c
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/5/10 8:13
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;

//单链表的存储结构
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//取值
Status GetElem(LinkList L, int i, ElemType *e) {
    struct LNode *p;
    int j = 1;
    p = L->next;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    *e = p->data;
    return OK;
}

//查找
int LocateElem_L(LinkList L, ElemType e) {
    struct LNode *p;
    int j = 1;
    p = L->next;
    while (p && p->data != e) {
        p = p->next;
        j++;
    }
    if (p) return j;
    else return 0;
}

//插入
Status ListInsert(LinkList L, int i, ElemType e) {
    int j = 0;
    LinkList p, s;
    p = L;
    while (p && (j < i - 1)) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;
    s = (LinkList) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

//删除
Status ListDelete(LinkList L, int i) {
    int j = 0;
    LinkList p, q;
    p = L;
    while ((p->next) && (j < i - 1)) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;
    q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}

//前插法创建单链表
void CreatList_H(LinkList L, int n) {
    int i;
    LinkList p;
    for (i = 0; i < n; ++i) {
        p = (LinkList) malloc(sizeof(LNode));
        printf("请输入元素：\n");
        scanf("%d", &(p->data));
        p->next = L->next;
        L->next = p;
    }
}

//后插法创建单链表
void CreatList_R(LinkList L, int n) {
    int i;
    LinkList r, p;
    r = L;
    for (i = 0; i < n; ++i) {
        p = (LinkList) malloc(sizeof(LNode));
        printf("请输入元素：\n");
        scanf("%d", &(p->data));
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

//测试
int main() {
    LinkList dlb, p;
    int temp, num, weizhi, choose;
    ElemType e;
    dlb = (LinkList) malloc(sizeof(LNode));
    dlb->next = NULL;
    printf("单链表初始化成功。\n");
    printf("操作序号如下(1和2每次只能选一个)：\n1：前插法创建单链表\n2：后插法创建单链表\n3：取值\n4：查找\n5：插入\n6：删除\n7：遍历\n0：退出\n");
    choose = -1;
    while (choose != 0) {
        printf("请输入操作序号：\n");
        scanf("%d", &choose);
        switch (choose) {

            case 1:
                printf("请输入元素的个数：\n");
                scanf("%d", &num);
                CreatList_H(dlb, num);
                printf("前插法创建单链表成功。\n");
                break;
            case 2:
                printf("请输入元素的个数：\n");
                scanf("%d", &num);
                CreatList_R(dlb, num);
                printf("后插法创建单链表成功。\n");
                break;
            case 3:
                printf("请输入取值位置：\n");
                scanf("%d", &weizhi);
                temp = GetElem(dlb, weizhi, &e);
                if (temp == OK)
                    printf("第%d个位置的元素是%d。\n", weizhi, e);
                else
                    printf("取值失败。\n");
                break;
            case 4:
                printf("请输入要查找的元素：\n");
                scanf("%d", &e);
                temp = LocateElem_L(dlb, e);
                if (temp != ERROR)
                    printf("查找成功，%d是单链表中的第%d个元素。\n", e, temp);
                else
                    printf("查找失败。\n");
                break;
            case 5:
                printf("请输入要插入的位置：\n");
                scanf("%d", &weizhi);
                printf("请输入要插入的元素：\n");
                scanf("%d", &e);
                temp = ListInsert(dlb, weizhi, e);
                if (temp == OK)
                    printf("插入成功。\n");
                else
                    printf("插入失败。\n");
                break;
            case 6:
                printf("请输入要删除的位置：\n");
                scanf("%d", &weizhi);
                temp = ListDelete(dlb, weizhi);
                if (temp == OK)
                    printf("删除成功。\n");
                else
                    printf("删除失败。\n");
                break;
            case 7:
                p = dlb->next;
                printf("单链表中的元素为：\n");
                while (p->next != NULL) {
                    printf("%d-->", p->data);
                    p = p->next;
                }
                printf("%d\n", p->data);
                break;
        }
    }

    system("pause");
    return 0;
}