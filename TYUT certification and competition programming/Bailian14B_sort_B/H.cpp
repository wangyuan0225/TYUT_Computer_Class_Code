#include <bits/stdc++.h>
using namespace std;

struct Task {
    int s;
    int d;
};

struct Rule {
    bool operator()(const Task &a, const Task &b) const {
        return a.d < b.d;
    }
};

int main() {
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        multiset<Task, Rule> tasks;
        for	(int i = 0; i < n; ++i) {
            Task p;
            cin >> p.s >> p.d;
            tasks.insert(p);
        }
        multiset<Task, Rule>::iterator i;
        int count = 1;
        i = tasks.begin();
        int d_tmp = (*i).d;
        while (i != tasks.end()) {
            if (d_tmp < (*(++i)).s) {
                count++;
                d_tmp = (*i).d;
            }
        }
        cout << count << endl;
    }
    return 0;
}