/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Strengthen_Practice
  * @File           : 03.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/5/10 11:37
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "../../../String.hpp"

using namespace std;

int Index(SString S, SString T);

int main() {
    SString S, T;
    StrAssign(S, "ababcabcacbab");
    StrAssign(T, "cab");
    cout << Index(S, T) << endl;
    return 0;
}

int Index(SString S, SString T) {
    int i = 1;
    int j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length) {
        return i - T.length;
    } else {
        return 0;
    }
}
