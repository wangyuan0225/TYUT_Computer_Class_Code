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

//˳���Ĵ洢�ṹ
typedef struct {
    ElemType *elem;
    int length;
} SqList;

//��ʼ��
Status InitList(SqList *L) {
    L->elem = (ElemType *) malloc(MAXSIZE * sizeof(ElemType));
    if (!L->elem)exit(OVERFLOW);
    L->length = 0;
    return OK;
}

//ȡֵ
Status GetElem(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) return ERROR;
    *e = L->elem[i - 1];
    return OK;
}

//����
int LocateElem(SqList *L, ElemType e) {
    int i;
    for (i = 0; i < L->length; i++)
        if (L->elem[i] == e) return i + 1;
    return 0;
}

//����
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

//ɾ��
Status ListDelete(SqList *L, int i) {
    int j;
    if ((i < 1) || (i > L->length)) return ERROR;
    for (j = i; j <= L->length - 1; j++)
        L->elem[j - 1] = L->elem[j];
    --L->length;
    return OK;
}

//����
int main() {
    int num, temp, i, choose, weizhi;
    ElemType e;
    SqList sxb;
    printf("���洢100������Ԫ�أ�������Ԫ�صĸ�����\n");
    scanf("%d", &num);
    temp = InitList(&sxb);
    if (temp == OK) {
        for (i = 0; i < num; i++) {
            printf("�������%d��Ԫ��:", i + 1);
            scanf("%d", &sxb.elem[i]);
            sxb.length++;
        }
    } else printf("˳�����ʧ�ܡ�");
    printf("����������£�\n1��ȡֵ\n2������\n3������\n4��ɾ��\n5������\n0���˳�\n");
    choose = -1;
    while (choose != 0) {
        printf("�����������ţ�\n");
        scanf("%d", &choose);
        switch (choose) {
            case 1:
                printf("������ȡֵλ�ã�\n");
                scanf("%d", &weizhi);
                temp = GetElem(&sxb, weizhi, &e);
                if (temp == OK)
                    printf("��%d��λ�õ�Ԫ����%d��\n", weizhi, e);
                else
                    printf("ȡֵʧ�ܡ�\n");
                break;
            case 2:
                printf("������Ҫ���ҵ�Ԫ�أ�\n");
                scanf("%d", &e);
                temp = LocateElem(&sxb, e);
                if (temp != ERROR)
                    printf("���ҳɹ���%d��˳����еĵ�%d��Ԫ�ء�\n", e, temp);
                else
                    printf("����ʧ�ܡ�\n");
                break;
            case 3:
                printf("������Ҫ�����λ�ã�\n");
                scanf("%d", &weizhi);
                printf("������Ҫ�����Ԫ�أ�\n");
                scanf("%d", &e);
                temp = ListInsert(&sxb, weizhi, e);
                if (temp == OK)
                    printf("����ɹ���\n");
                else
                    printf("����ʧ�ܡ�\n");
                break;
            case 4:
                printf("������Ҫɾ����λ�ã�\n");
                scanf("%d", &weizhi);
                temp = ListDelete(&sxb, weizhi);
                if (temp == OK)
                    printf("ɾ���ɹ���\n");
                else
                    printf("ɾ��ʧ�ܡ�\n");
                break;
            case 5:
                printf("��ǰ˳���Ϊ��\n");
                for (i = 0; i < sxb.length; i++)
                    printf("��%d��Ԫ�أ�%d\n", i + 1, sxb.elem[i]);

                break;
        }
    }


    return 0;
}
