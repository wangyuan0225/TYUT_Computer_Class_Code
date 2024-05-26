/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Strengthen_Practice
  * @File           : String.hpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/5/23 23:38
  * @Version        : 1.0
  ****************************************************************************************
  */

#ifndef STRENGTHEN_PRACTICE_STRING_HPP
#define STRENGTHEN_PRACTICE_STRING_HPP

#include <iostream>
#include <cstring>
#include "data_structures.hpp"

using namespace std;

const int MAXLEN = 255;

typedef struct {
    char ch[MAXLEN + 1];
    int length;
} SString;

Status StrAssign(SString &T, char *chars);

Status StrCopy(SString &T, SString S);

Status StrEmpty(SString S);

int StrCompare(SString S, SString T);

int StrLength(SString S);

Status ClearString(SString &S);

Status Concat(SString &T, SString S1, SString S2);

Status SubString(SString &Sub, SString S, int pos, int len);

int Index_BF(SString S, SString T, int pos);

Status StrInsert(SString &S, int pos, SString T);

Status StrDelete(SString &S, int pos, int len);

Status Replace(SString &S, SString T, SString V);

Status StrAssign(SString &T, char *chars) {
    if (strlen(chars) > MAXLEN) {
        return ERROR;
    }
    T.length = strlen(chars);
    for (int i = 1; i <= T.length; i++) {
        T.ch[i] = chars[i - 1];
    }
    return OK;
}

#endif //STRENGTHEN_PRACTICE_STRING_HPP
