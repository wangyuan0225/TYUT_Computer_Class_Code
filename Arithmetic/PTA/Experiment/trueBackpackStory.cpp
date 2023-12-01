#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> v(N+1), w(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    vector<vector<int>> count(N+1, vector<int>(W+1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i-1][j];
                count[i][j] = count[i-1][j];
            } else {
                if (dp[i-1][j] > dp[i-1][j-w[i]] + v[i]) {
                    dp[i][j] = dp[i-1][j];
                    count[i][j] = count[i-1][j];
                } else if (dp[i-1][j] < dp[i-1][j-w[i]] + v[i]) {
                    dp[i][j] = dp[i-1][j-w[i]] + v[i];
                    count[i][j] = count[i-1][j-w[i]] + 1;
                } else {
                    dp[i][j] = dp[i-1][j];
                    count[i][j] = min(count[i-1][j], count[i-1][j-w[i]] + 1);
                }
            }
        }
    }

    cout << dp[N][W] << " " << count[N][W] << endl;

    return 0;
}