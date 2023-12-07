#include <bits/stdc++.h>
using namespace std;
int mins = 100000;
int n;

int x[10000][10000] = {0};
int member[10000] ;
void SMIN(int ceng, int s, int d) {
    if (d == n && x[ceng][1]) {
        mins = min(mins, s + x[ceng][1]);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!member[i] && x[ceng][i]) {
            member[i] = 1;
            SMIN(i, s + x[ceng][i], d + 1);
            member[i] = 0;
        }
    }
}
int main() {
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> x[i][j];
        }
    }
    member[1] = 1;
    SMIN(1, 0, 1);
    cout << mins << endl;
    return 0;

}