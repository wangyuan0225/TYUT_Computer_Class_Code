#include <iostream>

using namespace std;

#define MAX 101
int n;
int arr[MAX][MAX];
int * maxSum;

int main() {
    int i, j;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= i; ++j) {
            cin >> arr[i][j];
        }
    }
    maxSum = arr[n];
    for (int i = n - 1;i >= 1; --i) {
        for (int j = 1;j <= i; ++j) {
            maxSum[j] = max(maxSum[j], maxSum[j + 1]) + arr[i][j];
        }
    }
    cout << maxSum[1] << endl;
    return 0;
}