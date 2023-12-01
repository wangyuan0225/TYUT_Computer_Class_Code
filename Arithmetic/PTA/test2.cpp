#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 128;

int p[MAXN], w[MAXN];
int dp[MAXN][MAXN], ik[MAXN][MAXN];
int coinCount[MAXN];

int main() {
    int n, Y;
    cin >> n >> Y;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    memset(dp, 64, sizeof(dp));
    memset(ik, 0, sizeof(ik));

    dp[0][0] = 0;

    for (int k = 1; k <= n; k++) {
        for (int y = 0; y <= Y; y++) {
            if (y >= p[k-1]) {
                int option1 = dp[k-1][y];
                int option2 = w[k-1] + dp[k][y - p[k-1]];
                if (option1 < option2) {
                    dp[k][y] = option1;
                    ik[k][y] = ik[k-1][y];
                } else {
                    dp[k][y] = option2;
                    ik[k][y] = k;
                }
            } else {
                dp[k][y] = dp[k-1][y];
                ik[k][y] = ik[k-1][y];
            }
        }
    }

    int k = n;
    int y = Y;
    while (y > 0 && k >= 1) {
        ///cout << ik[k][y] << endl;
        coinCount[ik[k][y]]++;
        y = y - p[ik[k][y]-1];
        k = k - 1;
    }


    int totalWeight = 0;
    for (int i = 1; i <= n; i++) {
        totalWeight += coinCount[i] * w[i-1];
    }

    for (int i = 1; i < n; i++) {
        cout << coinCount[i] << " ";
    }

    cout << coinCount[n] <<endl;
    cout << totalWeight ;

    return 0;
}