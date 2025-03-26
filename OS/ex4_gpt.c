#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 1024        // ÿ��������С
#define MEMORY_BLOCKS 4       // ��������������
#define TOTAL_PAGES 7         // ��ҵ����ҳ��

// ҳ����ṹ
typedef struct {
    int valid;                // ��־: 1��ʾ�����棬0��ʾ����
    int memoryBlock;          // ������
    int modified;             // �޸ı�־: 1��ʾ���޸ģ�0��ʾδ�޸�
    int diskPosition;         // ����λ��
} PageTableEntry;

// ��ʼ��ҳ��
void initPageTable(PT pageTable[]) {
    for (int i = 0; i < TOTAL_PAGES; i++) {
        pageTable[i].valid = (i < MEMORY_BLOCKS) ? 1 : 0;
        pageTable[i].memoryBlock = (i < MEMORY_BLOCKS) ? i : -1;
        pageTable[i].modified = 0;
        pageTable[i].diskPosition = 10 + i; // �������λ�ñ�Ŵ�10��ʼ
    }
}

// �����ǰҳ��״̬
void printPageTable(PT pageTable[]) {
    printf("ҳ��\t��־\t������\t�޸ı�־\t����λ��\n");
    for (int i = 0; i < TOTAL_PAGES; i++) {
        printf("%d\t%d\t%d\t\t%d\t\t%d\n",
               i, pageTable[i].valid, pageTable[i].memoryBlock,
               pageTable[i].modified, pageTable[i].diskPosition);
    }
    printf("\n");
}

// ģ���ַת����FIFOҳ�����
void simulateFIFO(PT pageTable[], int pageSequence[], int operations[], int sequenceLength) {
    int memoryQueue[MEMORY_BLOCKS]; // FIFO���У����ڴ洢��ǰ�������ҳ��
    int k = 0;                      // FIFOָ��
    int loadedPages = MEMORY_BLOCKS; // �Ѽ���ҳ������

    // ��ʼ���ڴ���FIFO����
    for (int i = 0; i < MEMORY_BLOCKS; i++) {
        memoryQueue[i] = i;
    }

    printf("��ʼģ��ִ��ָ������...\n\n");

    // ����ָ������
    for (int i = 0; i < sequenceLength; i++) {
        int page = pageSequence[i];
        int op = operations[i]; // 1��ʾ��д���򡰴桱��0��ʾ������

        printf("ָ��: %s ҳ��: %d\n", op ? "��" : "ȡ", page);

        if (pageTable[page].valid) { // ҳ��������
            printf("ҳ %d ������� %d\n", page, pageTable[page].memoryBlock);
            if (op) { // �����д�������޸ı�־��1
                pageTable[page].modified = 1;
            }
        } else { // ȱҳ�жϴ���
            printf("ȱҳ�ж�: ҳ %d\n", page);
            int oldPage = memoryQueue[k]; // Ҫ������ҳ��

            // �������ҳ����޸ı�־Ϊ1��ģ��д�ش���
            if (pageTable[oldPage].modified) {
                printf("OUT %d (д�ش���)\n", oldPage);
            } else {
                printf("OUT %d\n", oldPage);
            }

            // ����ҳ��������ҳ��װ����ҳ
            pageTable[oldPage].valid = 0;
            pageTable[oldPage].modified = 0;

            pageTable[page].valid = 1;
            pageTable[page].memoryBlock = pageTable[oldPage].memoryBlock;
            if (op) pageTable[page].modified = 1;

            memoryQueue[k] = page; // FIFO�滻

            printf("IN %d\n", page);

            // ����FIFOָ��
            k = (k + 1) % MEMORY_BLOCKS;
        }

        printPageTable(pageTable); // �����ǰҳ��״̬
    }
}

int main() {
    PT pageTable[TOTAL_PAGES];
    initPageTable(pageTable);

    // ���µ�ָ�����У�ҳ�ţ��Ͳ�����0��ʾ����1��ʾд��
    int pageSequence[] = {0, 4, 1, 5, 2, 1, 3, 2, 0, 4, 6, 6};
    int operations[]    = {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1}; // ���ݱ�3�Ĳ�������
    int sequenceLength = sizeof(pageSequence) / sizeof(pageSequence[0]);

    printf("��ʼҳ��״̬:\n");
    printPageTable(pageTable);

    simulateFIFO(pageTable, pageSequence, operations, sequenceLength);

    return 0;
}
