#include <bits/stdc++.h>

using namespace std;

struct Lesson {
    int p;
    int t;
    int days = 1;
    int latest;
    int last;
};

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<Lesson> lessons(m);
    for (int i = 0; i < m; ++i) {
        lessons[i].latest = n;
        lessons[i].last = n;
        cin >> lessons[i].p;
    }
    for (int i = 0; i < m; ++i) {
        cin >> lessons[i].t;
    }

    for (int i = 0; i < m; ++i) {
        if (lessons[i].p == 0) {
            continue;
        }
        int tmp = i;
        while (lessons[tmp].p != 0) {
            tmp = lessons[tmp].p;
            if (lessons[tmp - 1].days != 1) {
                lessons[i].days = lessons[tmp - 1].days + lessons[tmp - 1].t;
                break;
            }
            lessons[i].days += lessons[tmp - 1].t;
            tmp = lessons[tmp - 1].p;
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << lessons[i].days << " ";
    }
    cout << endl;

    bool isExceed = false;
    //冲击100
    for (int i = m - 1; i >= 0; --i) {
        if (lessons[i].latest == n) {
            lessons[i].latest -= lessons[i].t - 1;
        } else {
            lessons[i].latest -= lessons[i].t;
        }

        if (lessons[i].latest <= 0) {
            isExceed = true;
            break;
        }

        if (lessons[i].p != 0) {
            int tmp = lessons[i].p - 1;
            if (lessons[tmp].last > lessons[i].latest) {
                lessons[tmp].latest = lessons[i].latest;
                lessons[tmp].last = lessons[i].latest;
            }

            if (lessons[tmp].latest <= 0) {
                isExceed = true;
                break;
            }

        }
    }

    if (!isExceed) {
        for (int i = 0; i < m; ++i) {
            cout << lessons[i].latest << " ";
        }
    }

    return 0;
}