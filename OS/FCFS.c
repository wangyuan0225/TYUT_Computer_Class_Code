/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : OS
  * @File           : FCFS.c
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/11/11 10:30
  * @Version        : 1.0
  ****************************************************************************************
  */
// FCFS.c
#include <stdio.h>
#include <stdlib.h>

#define getpch(type) (type*)malloc(sizeof(type))
struct pcb { /*定义进程控制块*/
    char name[10]; //进程名
    char state; //进程状态："W"表示就绪，"R"表示运行
    int nice; //进程优先数（FCFS中不使用）
    int ntime; //需要运行的时间
    int rtime; //已经运行的时间
    struct pcb *link; //指向下一个进程
} *ready = NULL, *p;

typedef struct pcb PCB;

char input() {
    int i, num;
    printf("\n请输入被调度的进程数目：");
    scanf("%d", &num);
    for (i = 0; i < num; ++i) {
        printf("\n进程号 No.%d：", i);
        p = getpch(PCB);
        printf("\n输入进程名：");
        scanf("%s", p->name);
        printf("\n输入进程运行时间：");
        scanf("%d", &p->ntime);
        printf("\n");
        p->rtime = 0;
        p->state = 'W';
        p->link = NULL;

        if (ready == NULL) {
            ready = p;
        } else {
            PCB *temp = ready;
            while (temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = p;
        }
    }
}

int space() {
    int l = 0;
    PCB *pr = ready;
    while (pr != NULL) {
        l++;
        pr = pr->link;
    }
    return l;
}

char disp(PCB *pr) {
    printf("\n qname \t state \t ntime \t rtime \n");
    printf("%s\t", pr->name);
    printf("%c\t", pr->state);
    printf("%d\t", pr->ntime);
    printf("%d\t", pr->rtime);
    printf("\n");
}

char check() {
    PCB *pr;
    printf("\n**** 当前正在运行的进程是：%s", p->name);
    disp(p);
    pr = ready;
    if (pr != NULL) {
        printf("\n**** 当前就绪队列状态为：\n");
    } else {
        printf("\n**** 当前就绪队列状态为空\n");
    }
    while (pr != NULL) {
        disp(pr);
        pr = pr->link;
    }
}

char destroy() {
    printf("进程 [%s] 已完成.\n", p->name);
    free(p);
}

char running() {
    (p->rtime)++;
    if (p->rtime == p->ntime) {
        destroy();
    } else {
        p->state = 'W';
    }
}

int main() {
    int len, h = 0;
    char ch;
    input(); // 输入进程信息
    len = space();
    while ((len != 0) && (ready != NULL)) {
        ch = getchar();
        h++;
        printf("\n第 %d 次执行：\n", h);

        p = ready;
        ready = p->link;
        p->link = NULL;
        p->state = 'R';

        check();
        running();

        printf("\n按任意键继续...");
        ch = getchar();
        len = space(); // 重新计算剩余进程数目
    }
    printf("\n\n所有进程已经运行完成。\n");
    ch = getchar();
    return 0;
}
