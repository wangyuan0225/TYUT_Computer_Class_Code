/**
  ****************************************************************************************
  * Copyright &copy; Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : OS
  * @File           : ch3.c
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/10/21 15:06
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <stdio.h>
#include <stdlib.h>

// �����ź����ṹ��
typedef struct {
    int value;
    struct process *list;
} Semaphore;

// ��ʼ���ź���
Semaphore empty, orange, apple, mutex;
int buffer[5];
int in = 0, out = 0;


// block������ģ���������̣�
void block(struct process *list) {
    printf("��������\n");
    // ����Ӧ�ô������̹���Ĳ�������Ϊ��ӡ
}

// wakeup������ģ�⻽�ѽ��̣�
void wakeup(struct process *list) {
    printf("���̻���\n");
    // ����Ӧ�ô����ѽ��̵Ĳ�������Ϊ��ӡ
}

// �ȴ�������P������
void wait(Semaphore *S) {
    S->value--;
    if (S->value < 0)
        block(S->list);
}

// ���Ѳ�����V������
void signal(Semaphore *S) {
    S->value++;
    if (S->value <= 0)
        wakeup(S->list);
}

// Eat������ģ���ˮ���Ķ���
void Eat(char *fruit) {
    printf("��%s\n", fruit);
}

// ���׽���
void Dad() {
    int nextp;
    while (1) {
        wait(&empty);  // �ȴ������п�λ
        wait(&mutex);  // �ȴ�������
        nextp = rand() % 2;  // �����ƻ��(0)�����(1)
        buffer[in] = nextp;
        printf("�ְַ���һ��%s\n", nextp == 0 ? "ƻ��" : "����");
        in = (in + 1) % 5;  // ѭ��д�뻺����
        signal(&mutex);  // �ͷŻ�����
        if (nextp == 1)
            signal(&orange);  // �Ž��ӣ����Ѷ���
        else
            signal(&apple);   // ��ƻ��������Ů��
    }
}

// ���ӽ���
void Son() {
    int nexts;
    while (1) {
        wait(&orange);  // �ȴ��н���
        wait(&mutex);   // �ȴ�������
        nexts = buffer[out];
        out = (out + 1) % 5;  // ѭ����ȡ������
        signal(&mutex);  // �ͷŻ�����
        signal(&empty);  // �ͷ�һ����λ
        Eat("����");     // ���ӳԽ���
    }
}

// Ů������
void Daughter() {
    int nextt;
    while (1) {
        wait(&apple);   // �ȴ���ƻ��
        wait(&mutex);   // �ȴ�������
        nextt = buffer[out];
        out = (out + 1) % 5;  // ѭ����ȡ������
        signal(&mutex);  // �ͷŻ�����
        signal(&empty);  // �ͷ�һ����λ
        Eat("ƻ��");     // Ů����ƻ��
    }
}

// ���������
int main() {
    // ��ʼ���ź���
    empty.value = 5;
    orange.value = 0;
    apple.value = 0;
    mutex.value = 1;

    // ģ�Ⲣ��ִ�еĸ��ס����Ӻ�Ů������
    // ��ʵ�ʳ����У��ⲿ��Ӧ�����̻߳���̿ⴴ��
    // ����ֻ��˳��ģ�����
    Dad();  // ���Ը���ʵ����Ҫ��������ͬ�߳�������
    Son();
    Daughter();

    return 0;
}
