#include <bits/stdc++.h>
using namespace std;

struct mouse {
    int weight;
    string color;
};

struct Rule {
    bool operator()(const mouse &a, const mouse &b) const {
        return a.weight < b.weight;
    }
};

int main() {
    int n;
    cin >> n;
    multiset<mouse, Rule> mice;
    for	(int i = 0; i < n; ++i) {
        mouse m;
        cin >> m.weight >> m.color;
        mice.insert(m);
    }
    multiset<mouse, Rule>::iterator i;
    for	(i = mice.begin(); i != mice.end(); ++i) {
        cout << (*i).color << endl;
    }

    return 0;
}