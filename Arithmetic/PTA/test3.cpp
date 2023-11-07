/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : PTA
  * @File           : test3.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2023-11-07  00:09
  * @Version        : 1.0
  ****************************************************************************************
  */


#include<iostream>
using namespace std;
using ull = unsigned long long;
struct mat
{
    ull a_1_1,a_1_2,a_2_1,a_2_2;
}num_1;
mat mult(mat a, mat b)
{
    mat res;
    res.a_1_1 = a.a_1_1 * b.a_1_1 + a.a_1_2 * b.a_2_1;
    res.a_1_2 = a.a_1_1 * b.a_1_2 + a.a_1_2 * b.a_2_2;
    res.a_2_1 = a.a_2_1 * b.a_1_1 + a.a_2_2 * b.a_2_1;
    res.a_2_2 = a.a_2_1 * b.a_1_2 + a.a_2_2 * b.a_2_2;
    return res;
}
mat solve(ull num)
{
    if(num < 2)return num_1;
    if(num & 1)return mult(num_1,solve(num-1));
    return mult(solve(num/2),solve(num/2));
}
int main()
{
    ull num;
    cin >> num;
    num_1.a_1_1 = num_1.a_1_2 = num_1.a_2_1 = 1;
    num_1.a_2_2 = 0;
    mat ans = solve(num-1);
    cout << (ans.a_1_1%998244353);
    return 0;
}