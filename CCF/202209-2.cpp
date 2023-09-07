#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sum = 0, min;
    bool isExist = false;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += a[j];
            }
        }
        //测试 
//        cout << sum << " ";
        if (sum >= x && !isExist) {
            isExist = true;
            min = sum;
        }
        if (isExist && sum < min && sum >= x) {
            min = sum;
        }
        sum = 0;
    }
    cout << min << endl;
    return 0;
}