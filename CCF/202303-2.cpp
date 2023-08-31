#include <bits/stdc++.h>
using namespace std;

struct Site {
    int t;
    int c;
};

struct Rule {
    bool operator()(const Site &a, const Site &b) const {
        if (a.t == b.t) {
            return a.c > b.c;
        }
        return a.t > b.t;
    }
};


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    multiset<Site, Rule> sites;
    for (int i = 0; i < n; ++i) {
        Site site;
        cin >> site.t >> site.c;
        sites.insert(site);
    }
    multiset<Site, Rule>::iterator i;
    multiset<Site, Rule>::iterator it = sites.end();
    --it;
    int first = 0, tmp = 0;

    int t_tmp;
    //算第一次
    for (i = sites.begin(); i != it; ++i) {
        t_tmp = (*i).t;
        while (1) {
            if (t_tmp == (*(++i)).t) {
                --i;
                break;
            } else {
                --i;
            }
            first += (*i).c + tmp;
            if (first > m) {
                break;
            } else {
                t_tmp--;
            }
            if (t_tmp <= (*(++i)).t) {
                --i;
                break;
            } else {
                --i;
            }
        }
        tmp += (*i).c;
        if (first > m) {
            break;
        }
    }

    //算后续
    if (i == it) {
        int second = (*i).t, count = 0;
        for (i = sites.begin(); i != sites.end(); ++i) {
            count += (*i).c;
        }
        m -= first;
        if ((second - m / count) < k) {
            cout << k << endl;
        } else {
            cout << second - m / count << endl;
        }

    } else {
        cout << t_tmp << endl;
    }

    return 0;
}