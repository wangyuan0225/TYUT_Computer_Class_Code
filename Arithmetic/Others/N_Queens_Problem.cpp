/**
 * @BelongsProject: Others
 * @Author: yuan wang
 * @CreateTime: 2023-08-08  16:39
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cmath>
using namespace std;
int N;
int queenPos[100];

void NQueen(int k);

/**
 * @description: N 皇后问题
 * @author: yuan wang
 * @date: 2023/08/08 16:39
 * @param: null
 * @return: null
 */
int main() {
    cin >> N;
    NQueen(0);
    return 0;
}

/**
 * 在0~k-1行皇后已经摆好的情况下，摆第k行及其后的皇后
 * @param k
 */
void NQueen(int k) {
    int i;
    //N个皇后已经摆好
    if (k == N) {
        for (i = 0; i < N; i++) {
            cout << queenPos[i] + 1 << " ";
        }
        cout << endl;
        return;
    }
    //逐个尝试第k个皇后的位置
    for (i = 0; i < N; ++i) {
        int j;
        for (j = 0; j < k; ++j) {
            //和已经摆好的k个皇后的位置比较，即验证同一列以及斜着不能吃到，注意斜着不能被吃即表示行列差的绝对值不相等
            if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j)) {
                //冲突，测试下个位置
                break;
            }
        }
        if (j == k) {
            queenPos[k] = i;
            NQueen(k + 1);
        }
    }
}