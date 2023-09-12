#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double sum = 0;
    cin >> n;
    vector<double> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    double avg = sum / n;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (arr[i] - avg) * (arr[i] - avg);
    }
    double d = sum / n;

    for (int i = 0; i < n; ++i) {
        cout << (arr[i] - avg) / sqrt(d) << endl;
    }

    return 0;
}