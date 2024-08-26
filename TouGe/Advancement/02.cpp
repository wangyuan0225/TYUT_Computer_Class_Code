/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Advancement
  * @File           : 02.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 小张经彻夜研究，发现了规律：
                        第一行的数字随便是什么，以后每一行都是对上一行“读出来”
                        比如第 2 行，是对第 1 行的描述，意思是：1 个 1，1 个 3，所以是：1113
                        第 3 行，意思是：3 个 1,1 个 3，所以是：3113
                        请你编写一个程序，可以从初始数字开始，连续进行这样的变换。
  * @Attention      : None
  * @Date           : 2024/6/28 11:09
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str = to_string(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string temp;
        int count = 1;
        for (int j = 0; j < str.size(); ++j) {
            if (str[j] == str[j + 1]) {
                count++;
            } else {
                temp += to_string(count) + str[j];
                count = 1;
            }
        }
        str = temp;
        if (i == m - 1) {
            cout << str << endl;
        }
    }
    return 0;
}
