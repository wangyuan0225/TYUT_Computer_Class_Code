/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LQ
  * @File           : 5003.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 初始有一个空的01串，每步操作可以将0或1添加在左侧或右侧。也可以对整个串进行反异或
  *                     操作：取s'=s⊕reu(s)，其中s是目前的01串，⊕表示逐位异或，rev(s)代表将s翻转，
  *                     也就是说取中心位置并交换所有对称的两个位置的字符。例如，rev(0101)=1010,
  *                     rev(010)=010,rev(0011)=1100。反异或操作最多使用一次 (可以不用，也可以用一次)
  *                     给定一个01串T，问最少需要添加多少个1才能从一个空01串得到T。在本题中0可以添加任意个。
  * @Attention      : 输入一行包含一个01串表示给定的T。输出一行包含一个整数，表示需要最少添加多少个1。
  * @Date           : 2024/3/3 20:36
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ans++;
        }
    }
    if (ans % 2 == 0) {
        cout << ans / 2 << endl;
    } else {
        cout << ans / 2 + 1 << endl;
    }
    return 0;
}
