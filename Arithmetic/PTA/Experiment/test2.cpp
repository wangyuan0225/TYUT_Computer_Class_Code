#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int weight;
};

vector<int> dijkstra(int n, const vector<vector<Edge>>& graph) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false); // 记录顶点是否已被处理
    dist[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        // 找到未访问顶点中距离最小的顶点
        int u = -1;
        int minDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        // 更新相邻顶点的距离
        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (!visited[v] && dist[u] != INT_MAX && dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    return dist;
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    vector<int> shortestPaths = dijkstra(n, graph);

    // 输出除源点外的最短路径长度
    for (int i = 1; i < n; i++) {
        if (shortestPaths[i] != INT_MAX) {
            cout << shortestPaths[i] << " ";
        }
    }

    return 0;
}
