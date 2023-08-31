#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double i;
    cin >> n >> i;
    vector<double> money(n);
    for (int i = 0; i <= n; ++i) {
        cin >> money[i];
    }

    double sum = 0;
    for (int j = 0; j <= n; ++j) {
        sum += money[j] * pow(1 + i, -j);
    }
    cout << sum;
    return 0;
}