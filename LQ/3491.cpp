/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LQ
  * @File           : 3491.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 小蓝认为如果一个数含有偶数个数位，并且前面一半的数位之和等于后面一半的数位之和，则这
  *                     个数是他的幸运数字。例如2314是一个幸运数字，因为它有4个数位,并且2 + 3 = 1 + 4。
  *                     现在请你帮他计算从1至100000000之间共有多少个不同的幸运数字。
  * @Attention      : 这是一道结果填空的题，你只需要算出结果后提交即可。本题的结果为一个整数，在提交答案时
  *                     只填写这个整数，填写多余的内容将无法得分。
  * @Date           : 2024/3/13 21:00
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

int main() {
    int ans = 0;
    // 11-99 中的
    ans += 9;
    int left = 0, right = 0;
    for (int i = 1000; i <= 9999; i++) {
        left = i / 1000 + i % 1000 / 100;
        right = i % 100 / 10 + i % 10;
        if (left == right) {
            ans++;
        }
    }
    for (int i = 100000; i <= 999999; ++i) {
        left = i / 100000 + i % 100000 / 10000 + i % 10000 / 1000;
        right = i % 1000 / 100 + i % 100 / 10 + i % 10;
        if (left == right) {
            ans++;
        }
    }
    for (int i = 10000000; i <= 99999999; ++i) {
        left = i / 10000000 + i % 10000000 / 1000000 + i % 1000000 / 100000 + i % 100000 / 10000;
        right = i % 10000 / 1000 + i % 1000 / 100 + i % 100 / 10 + i % 10;
        if (left == right) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}