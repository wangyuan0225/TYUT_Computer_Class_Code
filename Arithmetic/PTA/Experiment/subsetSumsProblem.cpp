/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : subsetSumsProblem.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 设集合S={x1,x2,…,xn}是一个正整数集合，c是一个正整数，子集和问题判定是否存在S的
  *                     一个子集S1，使S1中的元素之和为c。试设计一个解子集和问题的回溯法，并输出利用回
  *                     溯法在搜索树（按输入顺序建立）中找到的第一个解。
  * @Attention      : 输入格式:
  *                     输入数据第1行有2个正整数n和c，n表示S的大小，c是子集和的目标值。接下来的1行中，
  *                     有n个正整数，表示集合S中的元素。
  *                   输出格式:
  *                     输出利用回溯法找到的第一个解，以空格分隔，最后一个输出的后面有空格。当问题无解时，输出“No Solution!”。
  * @Date           : 2023-12-01  22:57
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <vector>
using namespace std;

vector<int> S, solution;
int n, c;
bool found = false;

void backtrack(int sum, int index) {
    if (found) return;
    if (sum == c) {
        found = true;
        for (int i = 0; i < solution.size(); i++) {
            cout << solution[i] << " ";
        }
        cout << endl;
        return;
    }
    if (sum > c || index == n) return;
    solution.push_back(S[index]);
    backtrack(sum + S[index], index + 1);
    solution.pop_back();
    backtrack(sum, index + 1);
}

int main() {
    cin >> n >> c;
    S.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    backtrack(0, 0);
    if (!found) {
        cout << "No Solution!" << endl;
    }
    return 0;
}
