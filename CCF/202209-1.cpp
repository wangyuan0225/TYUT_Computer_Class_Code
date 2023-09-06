#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> c(n + 1);
    c[0] = 1;
    for (int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] * a[i - 1];
    }

    cout << m % c[1] / c[0] << " ";
    for (int i = 2; i <= n; ++i) {
        cout << (m % c[i] - m % c[i - 1]) / c[i - 1]<< " ";
    }

    return 0;
}