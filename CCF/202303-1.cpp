#include <bits/stdc++.h>
using namespace std;

struct Space {
    int x1;
    int y1;
    int x2;
    int y2;
};

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<Space> spaces(n);
    for (int i = 0; i < n; ++i) {
        Space space;
        cin >> space.x1 >> space.y1 >> space.x2 >> space.y2;
        spaces[i] = space;
    }
    int S = 0;
    for (int i = 0; i < n; ++i) {
        if (spaces[i].y1 >= b) {
            continue;
        } else if (spaces[i].x1 >= a) {
            continue;
        } else if (spaces[i].x1 <= 0 && spaces[i].y1 >= 0) {
            if (spaces[i].x2 < 0) {
                continue;
            } else if (spaces[i].x2 <= a) {
                if (spaces[i].y2 > b) {
                    S += (b - spaces[i].y1) * spaces[i].x2;
                    continue;
                } else {
                    S += (spaces[i].y2 - spaces[i].y1) * spaces[i].x2;
                    continue;
                }
            } else {
                if (spaces[i].y2 > b) {
                    S += (b - spaces[i].y1) * a;
                    continue;
                } else {
                    S += (spaces[i].y2 - spaces[i].y1) * a;
                    continue;
                }
            }
        } else if (spaces[i].x1 > 0 && spaces[i].y1 >= 0) {
            if (spaces[i].x2 <= a) {
                if (spaces[i].y2 > b) {
                    S += (b - spaces[i].y1) * (spaces[i].x2 - spaces[i].x1);
                    continue;
                } else {
                    S += (spaces[i].y2 - spaces[i].y1) * (spaces[i].x2 - spaces[i].x1);
                    continue;
                }
            } else {
                if (spaces[i].y2 > b) {
                    S += (b - spaces[i].y1) * (a - spaces[i].x1);
                    continue;
                } else {
                    S += (spaces[i].y2 - spaces[i].y1) * (a - spaces[i].x1);
                    continue;
                }
            }
        } else if (spaces[i].x1 <= 0 && spaces[i].y1 <= 0) {
            if (spaces[i].x2 <= 0 || spaces[i].y2 <= 0) {
                continue;
            } else if (spaces[i].x2 <= a) {
                if (spaces[i].y2 > b) {
                    S += b * spaces[i].x2;
                    continue;
                } else {
                    S += spaces[i].y2 * spaces[i].x2;
                    continue;
                }
            } else {
                if (spaces[i].y2 > b) {
                    S += b * a;
                    continue;
                } else {
                    S += spaces[i].y2 * a;
                    continue;
                }
            }
        } else {
            if (spaces[i].y2 <= 0) {
                continue;
            } else if (spaces[i].x2 <= a) {
                if (spaces[i].y2 > b) {
                    S += b * (spaces[i].x2 - spaces[i].x1);
                    continue;
                } else {
                    S += spaces[i].y2 * (spaces[i].x2 - spaces[i].x1);
                    continue;
                }
            } else {
                if (spaces[i].y2 > b) {
                    S += b * (a - spaces[i].x1);
                    continue;
                } else {
                    S += spaces[i].y2 * (a - spaces[i].x1);
                    continue;
                }
            }
        }
    }
    cout << S << endl;
    return 0;
}