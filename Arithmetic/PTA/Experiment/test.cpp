#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INFTY = INT_MAX;

struct Edge {
    int to;
    int weight;
};

typedef vector<vector<Edge>> Graph;

/**
 * Dijkstra's algorithm without priority queue
 * @param graph The graph
 * @param dist The shortest path lengths from the source vertex to each vertex
 */
void dijkstra(const Graph &graph, vector<int> &dist) {
    int n = graph.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        // Find the unvisited vertex with the smallest distance
        int minDist = INFTY, u = -1;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && dist[v] < minDist) {
                u = v;
                minDist = dist[v];
            }
        }

        // No vertex is reachable
        if (u == -1) break;

        visited[u] = true;

        // Relaxation step
        for (const auto &edge : graph[u]) {
            if (!visited[edge.to] && dist[edge.to] > dist[u] + edge.weight) {
                dist[edge.to] = dist[u] + edge.weight;
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    Graph graph(n);
    vector<int> dist(n, INFTY);
    dist[0] = 0; // The distance from the source vertex to itself is 0

    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dijkstra(graph, dist);

    // Print the result
    for (int i = 1; i < n; ++i) {
        if (dist[i] != INFTY) {
            cout << dist[i] << " ";
        }
    }

    return 0;
}
