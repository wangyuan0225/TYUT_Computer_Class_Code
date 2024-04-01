/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : CPPExperiment
  * @File           : singleSourceShortestPath.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : Compute the shortest path lengths from a given positive weight
  *                     directed graph. The graph contains n vertices numbered from 0 to n-1,
  *                     with vertex 0 as the source.
  * @Attention      : Input format:
  *                     The first line of input contains two positive integers n and e,
  *                     representing the number of vertices and edges of the graph, where n
  *                     does not exceed 20000 and e does not exceed 1000. The next e lines
  *                     represent the information of each edge, each line contains 3
  *                     non-negative integers a, b, and c, where a and b represent the
  *                     endpoint numbers of the edge, and c represents the weight. The edges
  *                     are not sorted in order of endpoint numbers.
  *                   Output format:
  *                     Output a line of integers, representing the shortest path lengths
  *                     from the source vertex 0 to each vertex in the order of vertex
  *                     numbers (excluding the distance from the source vertex to itself).
  *                     If there is no shortest path from the source vertex to a certain
  *                     vertex, do not output the distance for that path.
  * @Date           : 2023-12-02  09:38
  * @Version        : 2.0 Optimized the use of arrays
  *                   3.0 Optimized the algorithm using priority queue
  *                   4.0 Cancel the use of priority queues for implementation
  *                   5.0 Optimized the algorithm using adjacency lists
  ****************************************************************************************
  */

#include <iostream>
#include <vector>

using namespace std;

const int INFTY = 1e9;

struct Edge {
    int to;
    int weight;
};

/**
 * Dijkstra's algorithm
 * @param graph The graph
 * @param dist The shortest path lengths from the source vertex to each vertex
 */
void dijkstra(const vector<vector<Edge>> &graph, vector<int> &dist) {
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

        // Update the shortest paths of adjacent vertices.
        int size = graph[u].size();
        for (int j = 0; j < size; ++j) {
            const Edge &edge = graph[u][j];
            if (!visited[edge.to] && dist[edge.to] > dist[u] + edge.weight) {
                dist[edge.to] = dist[u] + edge.weight;
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<Edge>> graph(n);
    vector<int> dist(n, INFTY);
    // The distance from the source vertex to itself is 0
    dist[0] = 0;

    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        int index = graph[a].size();
        graph[a].resize(index + 1);
        graph[a][index].to = b;
        graph[a][index].weight = c;
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
