#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, Y;
    cin >> n >> Y;
    int p[n - 1], w[n - 1], f[100][100], i[100][100];
    for (int j = 0; j < n; j++) {
        cin >> p[j] ;
    }
    for (int j = 0; j < n; j++) {
        cin >> w[j] ;
    }

    for (int j = 0; j < 100; ++j) {
        for (int k = 0; k < 100; ++k) {
            f[j][k] = 1e9;
        }
    }

    f[0][0] = 0;
    for (int k = 1; k <= n; k++) {
        for (int y = 0; y <= Y; y++) {
            if (y >= p[k - 1]) {
                int point1 = f[k - 1][y];
                int point2 = w[k - 1] + f[k][(y - p[k - 1])];
                if (point1 < point2) {
                    f[k][y] = point1;
                    i[k][y] = i[k - 1][y];
                } else {
                    f[k][y] = point2;
                    i[k][y] = k;
                }
            } else {
                f[k][y] = f[k - 1][y];
                i[k][y] = i[k - 1][y];
            }
        }
    }

    int Num[100];
    int k = n;
    int y = Y;

    while (y > 0 && k >= 1) {
        Num[i[k][y]] += 1;
        y -= p[i[k][y] - 1];
        k -= 1;
    }

    int weight = 0;

    for (int j = 1; j <= n; j++) {
        weight += Num[j] * w[j - 1];
    }

    for (int j = 1; j < n; j++) {
        cout << Num[j] << " ";
    }

    cout << Num[n] << endl;
    cout << weight ;

    return 0;
}