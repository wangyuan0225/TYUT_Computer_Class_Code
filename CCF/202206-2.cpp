#include <bits/stdc++.h>
using namespace std;

struct tree {
    int x;
    int y;
};

struct Rule {
    bool operator()(const tree &a, const tree &b) const {
    }
};

int main() {
    int n, L, S;
    cin >> n >> L >> S;
    vector<tree> trees(n);
    for (int i = 0; i < n; ++i) {
        cin >> trees[i].x >> trees[i].y;
    }
    sort(trees.begin(), trees.end(), Rule());
    vector<vector<int> > arr(S + 1, vector<int>(S + 1));
    for (int i = S; i >= 0; --i) {
        for (int j = 0; j < S + 1; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {

    }
    return 0;
}
