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

// 定义信号量结构体
typedef struct {
    int value;
    struct process *list;
} Semaphore;

// 初始化信号量
Semaphore empty, orange, apple, mutex;
int buffer[5];
int in = 0, out = 0;


// block函数（模拟阻塞进程）
void block(struct process *list) {
    printf("进程阻塞\n");
    // 这里应该处理将进程挂起的操作，简化为打印
}

// wakeup函数（模拟唤醒进程）
void wakeup(struct process *list) {
    printf("进程唤醒\n");
    // 这里应该处理唤醒进程的操作，简化为打印
}

// 等待操作（P操作）
void wait(Semaphore *S) {
    S->value--;
    if (S->value < 0)
        block(S->list);
}

// 唤醒操作（V操作）
void signal(Semaphore *S) {
    S->value++;
    if (S->value <= 0)
        wakeup(S->list);
}

// Eat函数，模拟吃水果的动作
void Eat(char *fruit) {
    printf("吃%s\n", fruit);
}

// 父亲进程
void Dad() {
    int nextp;
    while (1) {
        wait(&empty);  // 等待盘子有空位
        wait(&mutex);  // 等待互斥锁
        nextp = rand() % 2;  // 随机放苹果(0)或桔子(1)
        buffer[in] = nextp;
        printf("爸爸放了一个%s\n", nextp == 0 ? "苹果" : "桔子");
        in = (in + 1) % 5;  // 循环写入缓冲区
        signal(&mutex);  // 释放互斥锁
        if (nextp == 1)
            signal(&orange);  // 放桔子，唤醒儿子
        else
            signal(&apple);   // 放苹果，唤醒女儿
    }
}

// 儿子进程
void Son() {
    int nexts;
    while (1) {
        wait(&orange);  // 等待有桔子
        wait(&mutex);   // 等待互斥锁
        nexts = buffer[out];
        out = (out + 1) % 5;  // 循环读取缓冲区
        signal(&mutex);  // 释放互斥锁
        signal(&empty);  // 释放一个空位
        Eat("桔子");     // 儿子吃桔子
    }
}

// 女儿进程
void Daughter() {
    int nextt;
    while (1) {
        wait(&apple);   // 等待有苹果
        wait(&mutex);   // 等待互斥锁
        nextt = buffer[out];
        out = (out + 1) % 5;  // 循环读取缓冲区
        signal(&mutex);  // 释放互斥锁
        signal(&empty);  // 释放一个空位
        Eat("苹果");     // 女儿吃苹果
    }
}

// 主程序入口
int main() {
    // 初始化信号量
    empty.value = 5;
    orange.value = 0;
    apple.value = 0;
    mutex.value = 1;

    // 模拟并发执行的父亲、儿子和女儿进程
    // 在实际场景中，这部分应该由线程或进程库创建
    // 这里只是顺序模拟调用
    Dad();  // 可以根据实际需要，启动不同线程来运行
    Son();
    Daughter();

    return 0;
}
