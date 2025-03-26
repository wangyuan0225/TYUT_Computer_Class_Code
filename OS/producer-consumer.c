/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : OS
  * @File           : producer-consumer.c
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/11/14 13:54
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX 256
char *buffer;
sem_t empty;
sem_t full;
sem_t mutex;

void *producer() {
    sem_wait(&empty);
    sem_wait(&mutex);
    printf("input something to buffer:");
    buffer = (char *) malloc(MAX);
    fgets(buffer, MAX, stdin);
    sem_post(&mutex);
    sem_post(&full);
}

void *consumer() {
    sem_wait(&full);	//full的P操作
    sem_wait(&mutex);	//mutex的P操作
    printf("read product from buffer:%s",buffer); //从缓冲区中取出产品
    memset(buffer,0,MAX);		//清空缓冲区
    sem_post(&mutex);	//mutex的V操作
    sem_post(&empty);	//empty的V操作
}

int main() {
    pthread_t id_producer;
    pthread_t id_consumer;
    int ret;
    sem_init(&empty, 0, 10);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    ret = pthread_create(&id_producer, NULL, producer, NULL);
    ret = pthread_create(&id_consumer, NULL, consumer, NULL);
    pthread_join(id_producer, NULL);
    pthread_join(id_consumer, NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    printf("The End...\n");
    return 0;
}
