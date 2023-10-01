#include <bits/stdc++.h>
using namespace std;
int ** T(int *x[]);

int main() {
    int a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }
    int **b = T((int **)a);
    cout << b[3][3] << endl ;
    return 0;
}

int ** T(int *x[]) {
    int c[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            c[i][j] = x[j][i];
    }
    return (int **)c;
}