#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, Y;
    cin >> n >> Y;
    vector<int> p(n), w(n), dp(Y + 1, INT_MAX), coinCount(n, 0), coinUsed(Y + 1, -1);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = p[i]; j <= Y; ++j) {
            if (dp[j - p[i]] != INT_MAX && dp[j - p[i]] + w[i] < dp[j]) {
                dp[j] = dp[j - p[i]] + w[i];
                coinUsed[j] = i;
            }
        }
    }

    if (dp[Y] == INT_MAX) {
        cout << "No solution";
    } else {
        int y = Y;
        while (y > 0) {
            coinCount[coinUsed[y]]++;
            y -= p[coinUsed[y]];
        }
        for (int i = 0; i < n; ++i) {
            cout << coinCount[i] << " ";
        }
        cout << endl << dp[Y];
    }

    return 0;
}