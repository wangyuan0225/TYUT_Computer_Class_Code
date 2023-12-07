/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : test3.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2023-12-02  00:02
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = -1;
const int AC = 1e5+1;
vector<int> v,s;
int main()
{
    int n,e;cin >> n >> e;
    int a[n][n],l[n],dist[n];
    int tmp1,tmp2,tmp3,tmp4,d_min;
    memset(a,MAX,sizeof(a));
    memset(l,MAX,sizeof(l));
    memset(dist,MAX,sizeof(dist));
    for(int i = 0;i < e;i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        a[tmp1][tmp2] = tmp3;
    }
    for(int i = 1;i < n;i++)v.push_back(i);
    s.push_back(0);
    dist[0] = 0;
    for(auto val : v)dist[val] = a[0][val];
    while(!v.empty())
    {
        tmp4 = 0;
        for(auto val : v)
        {
            tmp1 = AC;
            d_min = AC;
            tmp4++;
            for(auto sal : s)
                if(a[sal][val] != MAX)
                {
                    tmp1 = min(dist[sal] + a[sal][val],tmp1);
                    tmp2 = sal;
                }
            if(tmp1 != MAX && tmp1 != AC && tmp1 < d_min)
            {
                d_min = tmp1;
                tmp3 = val;
            }
        }
        s.push_back(tmp3);
        /*v.erase(find(v.begin(),v.end(),tmp3));*/
        /*vector<int>v_p(v);
        v.clear();
        for(auto val : v_p)
        {
            if(val != tmp3)v.push_back(val);
        }*/
        auto iter = v.begin();
        while (iter != v.end())
        {
            if (*iter == tmp3) iter = v.erase(iter);
            else ++iter;
        }
        l[tmp3] = tmp2;
        for(auto sal : s)
            if(dist[tmp3] + a[tmp3][sal] < dist[sal])dist[sal] = dist[tmp3] + a[tmp3][sal];
    }
    for(tmp1 = 1;tmp1 < n;tmp1++)
        if(l[tmp1] != MAX)
        {
            cout << l[tmp1];
            break;
        }
    for(;tmp1 < n;tmp1++)if(l[tmp1] != MAX)cout << " " << l[tmp1];
    return 0;
}