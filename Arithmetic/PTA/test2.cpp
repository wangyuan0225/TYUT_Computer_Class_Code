/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : PTA
  * @File           : test2.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2023-11-07  00:07
  * @Version        : 1.0
  ****************************************************************************************
  */


#include <iostream>
#include<cstdio>
using namespace std;
#define mod 998244353
typedef unsigned long long ll;

void fastPower(ll a[2][2], ll b[2][2]);
ll Fibonacci(ll n) {
    if (n < 2) return 1;
    ll end[2][2] = { {1,0},{0,1} };//结束矩阵
    ll begin[2][2] = { {1,1},{1,0} };//底数矩阵
    while (n) {
        if (n & 1) {//质数为偶数
            fastPower(end, begin);//
        }
        n = n >> 1;//指数减半
        fastPower(begin, begin);//底数平方
    }
    return end[0][1];
}
void fastPower(ll a[2][2], ll b[2][2]) {//快速幂
    int temp[2][2] = { {0,0},{0,0} };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                temp[i][j] = (temp[i][j]+ a[i][k] * b[k][j])%mod;//矩阵乘法
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = temp[i][j];//修改结束矩阵的值
        }
    }
}

int main() {
    ll n;
    cin>>n;
    cout<<Fibonacci(n);
}