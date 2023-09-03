#include <bits/stdc++.h>
using namespace std;

struct Lesson {
    int p;
    int t;
    int days = 1;
};


int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<Lesson> lessons(m);
    for (int i = 0; i < m; ++i) {
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

//	bool isExpeed = false;
//
//	for (int i = 0; i < m; ++i) {
//		if (lessons[i].t > n + 1) {
//			isExpeed = true;
//			break;
//		}
//	}
//
//	if (!isExpeed) {
//		for (int i = 0; i < m; ++i) {
//			cout << n + 1 - lessons[i].t << " ";
//		}
//	}

    return 0;
}