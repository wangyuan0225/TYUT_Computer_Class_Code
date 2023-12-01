/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : singleSourceShortestPath.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 求给定正权有向图的单源最短路径长度。图中包含n个顶点，编号为0至n-1，以顶点0作为源
  *                     点。
  * @Attention      : 输入格式:
  *                     输入第一行为两个正整数n和e，分别表示图的顶点数和边数，其中n不超过20000，e不超
  *                     过1000。接下来e行表示每条边的信息，每行为3个非负整数a、b、c，其中a和b表示该边
  *                     的端点编号，c表示权值。各边并非按端点编号顺序排列。
  *                   输出格式:
  *                     输出为一行整数，为按顶点编号顺序排列的源点0到各顶点的最短路径长度（不含源点到源
  *                     点），每个整数后一个空格。如源点到某顶点无最短路径，则不输出该条路径长度。
  * @Date           : 2023-12-01  20:39
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

struct Edge {
    int to;
    int weight;
};

int main () {
    int n, e;
    cin >> n >> e;


    return 0;
}

