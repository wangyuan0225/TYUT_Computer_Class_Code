#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<vector<int>> Q(n, vector<int>(d));
    vector<vector<int>> K(n, vector<int>(d));
    vector<vector<int>> V(n, vector<int>(d));
    vector<int> W(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> Q[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> K[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> V[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> W[i];
    }

    vector<vector<long long>> result(n, vector<long long>(d, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long dot_product = 0;
            for (int k = 0; k < d; ++k) {
                dot_product += static_cast<long long>(Q[i][k]) * K[j][k];
            }
            for (int k = 0; k < d; ++k) {
                result[i][k] += dot_product * V[j][k];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < d; ++k) {
            result[i][k] *= W[i];
            cout << result[i][k];
            if (k != d - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
