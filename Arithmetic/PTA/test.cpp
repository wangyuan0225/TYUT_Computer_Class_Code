/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : PTA
  * @File           : test.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2023-11-15  22:15
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 表示图中的边的结构体模板
template <typename T>
struct Edge {
    int destination;  // 目标顶点
    T weight;         // 权重
};

// 表示图中的顶点的结构体模板
template <typename T>
struct Vertex {
    vector<Edge<T>> edges;  // 邻接链表
};

// 表示动态分阶的图的类模板
template <typename T>
class DynamicStageGraph {
private:
    int numStages;                   // 图的阶段数
    unordered_map<int, int> stages;  // 顶点所属的阶段

public:
    vector<Vertex<T>> graph;         // 图的顶点集合

    // 构造函数
    DynamicStageGraph() : numStages(0) {
        // 初始化图的每个阶段
        graph.emplace_back();  // 添加一个空的阶段，使图从1开始
    }

    // 添加边的方法
    void addEdge(int source, int destination, T weight) {
        Edge<T> edge = {destination, weight};
        graph[source].edges.push_back(edge);
        updateStages(source, destination);
    }

    // 更新顶点的阶段信息
    void updateStages(int source, int destination) {
        stages[source] = numStages;
        stages[destination] = numStages + 1;
        numStages += 2;

        // 确保图的每个阶段都有对应的空顶点
        while (graph.size() <= numStages) {
            graph.emplace_back();
        }
    }

    // 打印图的方法
    void printGraph() {
        for (int i = 1; i < graph.size(); ++i) {
            cout << "Stage " << i << ": ";
            for (const Edge<T>& edge : graph[i].edges) {
                cout << "(" << edge.destination << ", " << edge.weight << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    // 创建动态分阶的图对象，使用int类型作为权重的例子
    DynamicStageGraph<int> graph;

    // 添加边
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 4, 1);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 6, 2);
    graph.addEdge(3, 7, 5);

    // 打印图
    graph.printGraph();

    return 0;
}
