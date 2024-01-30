/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : PTA
  * @File           : multiSegmentDiagrams.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : s和t分别为图G的唯一的源点和汇点。多段图问题即求s到t的最短路径。
  * @Attention      : 利用「备忘录方法」或者「迭代递推」实现对多段图问题进行编程求解。
  * @Date           : 2023-11-13  22:04
  * @Version        : 2.0 针对格式以及图类等地方进行修改完善，增加相应注释
  ****************************************************************************************
  */

#include <iostream>
#include <vector>

using namespace std;

//定义无穷大
const int INFTY = 1e9;


template<class T>
struct ENode {
    int adjVex;         //顶点编号
    T w;                //赋权值weight
    //用于连接同一个顶点的所有出边，形成一个链表。
    //这种表示方法允许有效地存储和遍历从特定顶点出发的所有边。
    ENode<T> *nextArc;

    ENode() : nextArc(nullptr) {}

    ENode(int v, T weight) : adjVex(v), w(weight), nextArc(nullptr) {}
};

template<class T>
class Graph {
public:
    ENode<T> **a;       //二级指针，存储所有顶点
    int n;              //存储顶点数目

    Graph(int size) : n(size) {
        a = new ENode<T> *[n];
        //初始化顶点数组为空指针
        for (int i = 0; i < n; ++i) {
            a[i] = nullptr;
        }
    }

    ~Graph() {
        for (int i = 0; i < n; ++i) {
            ENode<T> *node = a[i];
            while (node != nullptr) {
                //定义temp防止删除的时候无法访问到删除顶点的邻接顶点
                ENode<T> *temp = node;
                node = node->nextArc;
                delete temp;
            }
        }
        //构造函数中new出来的a，需要用delete[]删除
        delete[] a;
    }

    void addEdge(int start, int end, T weight) {
        ENode<T> *newEdge = new ENode<T>(end, weight);
        //将新边的nextArc指针设置为当前起始顶点的邻接链表的头部
        newEdge->nextArc = a[start];
        //将起始顶点的邻接链表头部更新为新边
        a[start] = newEdge;
    }

    void FMultiGraph(int k, int *p);
};

/**
 * 计算最短路径
 * @tparam T 赋权的参数类型
 * @param k 顶点数
 * @param p 标记函数
 */
template<class T>
void Graph<T>::FMultiGraph(int k, int *p) {
    float *cost = new float[n];
    int q, *d = new int[n];
    cost[n - 1] = 0, d[n - 1] = -1;
    for (int j = n - 2; j >= 0; --j) {
        float min = INFTY;
        for (ENode<T> *r = a[j]; r; r = r->nextArc) {
            int v = r->adjVex;
            if (r->w + cost[v] < min) {
                min = r->w + cost[v];
                q = v;
            }
        }
        cost[j] = min;
        d[j] = q;
    }
    p[0] = 0;
    p[k - 1] = n - 1;
    for (int j = 1; j <= k - 2; j++) {
        p[j] = d[p[j - 1]];
        if (p[j] == -1) {
            break;
        }
    }
    for (int i = 0; i < k; ++i) {
        if (p[i + 1] == -1) {
            cout << p[i];
            break;
        }
        cout << p[i] << " ";
    }
    cout << endl << cost[0];
    delete[]cost;
    delete[]d;
}

int main() {
    int m, n;
    cin >> m >> n;
    Graph<int> graph(m);
    for (int i = 0; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }
    int *p = new int[m];
    graph.FMultiGraph(m, p);
    return 0;
}
