#include <bits/stdc++.h>
using namespace std;

struct Space {
    int x1;
    int y1;
    int x2;
    int y2;
};

int countSpace(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (y2 - y1);
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<Space> spaces(n);
    for (int i = 0; i < n; ++i) {
        Space space;
        cin >> space.x1 >> space.y1 >> space.x2 >> space.y2;
        if (space.x1 < 0) {
            space.x1 = 0;
        }
        if (space.x2 > a) {
            space.x2 = a;
        }
        if (space.y1 < 0) {
            space.y1 = 0;
        }
        if (space.y2 > b) {
            space.y2 = b;
        }
        spaces[i] = space;
    }
    int S = 0;
    for (int i = 0; i < n; ++i) {
        if (spaces[i].x1 > a) {
            continue;
        }
        if (spaces[i].x2 < 0) {
            continue;
        }
        if (spaces[i].y1 > b) {
            continue;
        }
        if (spaces[i].y2 < 0) {
            continue;
        }
        S += countSpace(spaces[i].x1, spaces[i].y1, spaces[i].x2, spaces[i].y2);
    }
    cout << S << endl;
    return 0;
}