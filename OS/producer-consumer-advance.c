/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : OS
  * @File           : producer-consumer-advance.c
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/11/14 14:37
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX 256
#define BUFFER_SIZE 5  // 缓冲区大小
char *buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void *producer() {
    for (int i = 0; i < 10; i++) {  // 生产10次
        sem_wait(&empty);  // 等待空缓冲区
        pthread_mutex_lock(&mutex);  // 锁定临界区

        buffer[in] = (char *)malloc(MAX);  // 为缓冲区分配内存
        printf("Producer: input something to buffer: ");
        fgets(buffer[in], MAX, stdin);
        in = (in + 1) % BUFFER_SIZE;  // 更新缓冲区指针

        pthread_mutex_unlock(&mutex);  // 解锁临界区
        sem_post(&full);  // 增加满缓冲区计数
    }
    return NULL;
}

void *consumer() {
    for (int i = 0; i < 10; i++) {  // 消费10次
        sem_wait(&full);  // 等待满缓冲区
        pthread_mutex_lock(&mutex);  // 锁定临界区

        printf("Consumer: buffer content is %s", buffer[out]);
        free(buffer[out]);  // 释放缓冲区内存
        out = (out + 1) % BUFFER_SIZE;  // 更新缓冲区指针

        pthread_mutex_unlock(&mutex);  // 解锁临界区
        sem_post(&empty);  // 增加空缓冲区计数
    }
    return NULL;
}

int main() {
    pthread_t id_producer, id_consumer;

    sem_init(&empty, 0, BUFFER_SIZE);  // 初始化空缓冲区信号量
    sem_init(&full, 0, 0);  // 初始化满缓冲区信号量
    pthread_mutex_init(&mutex, NULL);  // 初始化互斥锁

    pthread_create(&id_producer, NULL, producer, NULL);
    pthread_create(&id_consumer, NULL, consumer, NULL);

    pthread_join(id_producer, NULL);
    pthread_join(id_consumer, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    printf("The End...\n");
    return 0;
}
