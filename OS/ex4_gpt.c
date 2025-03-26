#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 1024        // 每块主存块大小
#define MEMORY_BLOCKS 4       // 分配的主存块数量
#define TOTAL_PAGES 7         // 作业的总页数

// 页表项结构
typedef struct {
    int valid;                // 标志: 1表示在主存，0表示不在
    int memoryBlock;          // 主存块号
    int modified;             // 修改标志: 1表示已修改，0表示未修改
    int diskPosition;         // 磁盘位置
} PageTableEntry;

// 初始化页表
void initPageTable(PT pageTable[]) {
    for (int i = 0; i < TOTAL_PAGES; i++) {
        pageTable[i].valid = (i < MEMORY_BLOCKS) ? 1 : 0;
        pageTable[i].memoryBlock = (i < MEMORY_BLOCKS) ? i : -1;
        pageTable[i].modified = 0;
        pageTable[i].diskPosition = 10 + i; // 假设磁盘位置编号从10开始
    }
}

// 输出当前页表状态
void printPageTable(PT pageTable[]) {
    printf("页号\t标志\t主存块号\t修改标志\t磁盘位置\n");
    for (int i = 0; i < TOTAL_PAGES; i++) {
        printf("%d\t%d\t%d\t\t%d\t\t%d\n",
               i, pageTable[i].valid, pageTable[i].memoryBlock,
               pageTable[i].modified, pageTable[i].diskPosition);
    }
    printf("\n");
}

// 模拟地址转换和FIFO页面调度
void simulateFIFO(PT pageTable[], int pageSequence[], int operations[], int sequenceLength) {
    int memoryQueue[MEMORY_BLOCKS]; // FIFO队列，用于存储当前在主存的页号
    int k = 0;                      // FIFO指针
    int loadedPages = MEMORY_BLOCKS; // 已加载页面数量

    // 初始化内存块的FIFO队列
    for (int i = 0; i < MEMORY_BLOCKS; i++) {
        memoryQueue[i] = i;
    }

    printf("开始模拟执行指令序列...\n\n");

    // 遍历指令序列
    for (int i = 0; i < sequenceLength; i++) {
        int page = pageSequence[i];
        int op = operations[i]; // 1表示“写”或“存”，0表示“读”

        printf("指令: %s 页号: %d\n", op ? "存" : "取", page);

        if (pageTable[page].valid) { // 页在主存中
            printf("页 %d 在主存块 %d\n", page, pageTable[page].memoryBlock);
            if (op) { // 如果是写操作，修改标志置1
                pageTable[page].modified = 1;
            }
        } else { // 缺页中断处理
            printf("缺页中断: 页 %d\n", page);
            int oldPage = memoryQueue[k]; // 要调出的页面

            // 如果调出页面的修改标志为1，模拟写回磁盘
            if (pageTable[oldPage].modified) {
                printf("OUT %d (写回磁盘)\n", oldPage);
            } else {
                printf("OUT %d\n", oldPage);
            }

            // 更新页表，调出旧页，装入新页
            pageTable[oldPage].valid = 0;
            pageTable[oldPage].modified = 0;

            pageTable[page].valid = 1;
            pageTable[page].memoryBlock = pageTable[oldPage].memoryBlock;
            if (op) pageTable[page].modified = 1;

            memoryQueue[k] = page; // FIFO替换

            printf("IN %d\n", page);

            // 更新FIFO指针
            k = (k + 1) % MEMORY_BLOCKS;
        }

        printPageTable(pageTable); // 输出当前页表状态
    }
}

int main() {
    PT pageTable[TOTAL_PAGES];
    initPageTable(pageTable);

    // 更新的指令序列（页号）和操作（0表示读，1表示写）
    int pageSequence[] = {0, 4, 1, 5, 2, 1, 3, 2, 0, 4, 6, 6};
    int operations[]    = {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1}; // 根据表3的操作更新
    int sequenceLength = sizeof(pageSequence) / sizeof(pageSequence[0]);

    printf("初始页表状态:\n");
    printPageTable(pageTable);

    simulateFIFO(pageTable, pageSequence, operations, sequenceLength);

    return 0;
}
