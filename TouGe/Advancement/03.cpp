#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};

struct Edge {
    int to;
    double weight;
    Edge(int to, double weight) : to(to), weight(weight) {}
};

double distance(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool isBlocked(const Point &a, const Point &b, const vector<vector<double>> &walls) {
    for (const auto &wall : walls) {
        double wx = wall[0]; // x coordinate of the wall
        if ((a.x < wx && wx < b.x) || (b.x < wx && wx < a.x)) {
            if (!((wall[1] <= a.y && a.y <= wall[2]) || (wall[3] <= a.y && a.y <= wall[4]))) {
                return true;
            }
        }
    }
    return false;
}

double dijkstra(const vector<Point> &points, const vector<vector<Edge>> &graph, int start, int end) {
    int n = points.size();
    vector<double> dist(n, numeric_limits<double>::infinity());
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;

    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        double d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto &edge : graph[u]) {
            int v = edge.to;
            double weight = edge.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist[end];
}

int main() {
    int n;
    cin >> n;
    vector<Point> points;
    vector<vector<Edge>> graph;

    points.emplace_back(0, 5); // Start point
    points.emplace_back(10, 5); // End point

    vector<vector<double>> walls;
    for (int i = 0; i < n; ++i) {
        double x, a1, b1, a2, b2;
        cin >> x >> a1 >> b1 >> a2 >> b2;
        walls.push_back({x, a1, b1, a2, b2});
        points.emplace_back(x, a1);
        points.emplace_back(x, b1);
        points.emplace_back(x, a2);
        points.emplace_back(x, b2);
    }

    int m = points.size();
    graph.resize(m);

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (!isBlocked(points[i], points[j], walls)) {
                double dist = distance(points[i], points[j]);
                graph[i].emplace_back(j, dist);
                graph[j].emplace_back(i, dist);
            }
        }
    }

    double result = dijkstra(points, graph, 0, 1);
    cout << fixed << setprecision(2) << result << endl;

    return 0;
}