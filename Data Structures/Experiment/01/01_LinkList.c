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

//������Ĵ洢�ṹ
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//ȡֵ
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

//����
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

//����
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

//ɾ��
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

//ǰ�巨����������
void CreatList_H(LinkList L, int n) {
    int i;
    LinkList p;
    for (i = 0; i < n; ++i) {
        p = (LinkList) malloc(sizeof(LNode));
        printf("������Ԫ�أ�\n");
        scanf("%d", &(p->data));
        p->next = L->next;
        L->next = p;
    }
}

//��巨����������
void CreatList_R(LinkList L, int n) {
    int i;
    LinkList r, p;
    r = L;
    for (i = 0; i < n; ++i) {
        p = (LinkList) malloc(sizeof(LNode));
        printf("������Ԫ�أ�\n");
        scanf("%d", &(p->data));
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

//����
int main() {
    LinkList dlb, p;
    int temp, num, weizhi, choose;
    ElemType e;
    dlb = (LinkList) malloc(sizeof(LNode));
    dlb->next = NULL;
    printf("�������ʼ���ɹ���\n");
    printf("�����������(1��2ÿ��ֻ��ѡһ��)��\n1��ǰ�巨����������\n2����巨����������\n3��ȡֵ\n4������\n5������\n6��ɾ��\n7������\n0���˳�\n");
    choose = -1;
    while (choose != 0) {
        printf("�����������ţ�\n");
        scanf("%d", &choose);
        switch (choose) {

            case 1:
                printf("������Ԫ�صĸ�����\n");
                scanf("%d", &num);
                CreatList_H(dlb, num);
                printf("ǰ�巨����������ɹ���\n");
                break;
            case 2:
                printf("������Ԫ�صĸ�����\n");
                scanf("%d", &num);
                CreatList_R(dlb, num);
                printf("��巨����������ɹ���\n");
                break;
            case 3:
                printf("������ȡֵλ�ã�\n");
                scanf("%d", &weizhi);
                temp = GetElem(dlb, weizhi, &e);
                if (temp == OK)
                    printf("��%d��λ�õ�Ԫ����%d��\n", weizhi, e);
                else
                    printf("ȡֵʧ�ܡ�\n");
                break;
            case 4:
                printf("������Ҫ���ҵ�Ԫ�أ�\n");
                scanf("%d", &e);
                temp = LocateElem_L(dlb, e);
                if (temp != ERROR)
                    printf("���ҳɹ���%d�ǵ������еĵ�%d��Ԫ�ء�\n", e, temp);
                else
                    printf("����ʧ�ܡ�\n");
                break;
            case 5:
                printf("������Ҫ�����λ�ã�\n");
                scanf("%d", &weizhi);
                printf("������Ҫ�����Ԫ�أ�\n");
                scanf("%d", &e);
                temp = ListInsert(dlb, weizhi, e);
                if (temp == OK)
                    printf("����ɹ���\n");
                else
                    printf("����ʧ�ܡ�\n");
                break;
            case 6:
                printf("������Ҫɾ����λ�ã�\n");
                scanf("%d", &weizhi);
                temp = ListDelete(dlb, weizhi);
                if (temp == OK)
                    printf("ɾ���ɹ���\n");
                else
                    printf("ɾ��ʧ�ܡ�\n");
                break;
            case 7:
                p = dlb->next;
                printf("�������е�Ԫ��Ϊ��\n");
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