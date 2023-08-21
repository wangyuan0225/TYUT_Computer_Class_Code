#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int a[], int s, int e) {
    int pivot = a[e];
    int i = s - 1;
    for (int j = s; j <= e - 1; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}

void arrangeRight(int a[], int s, int e, int k) {
    if (s <= e) {
        int p = partition(a, s, e);
        int len = e - p + 1;  // Length of the right part of the array after partition
        if (k == len) {
            return;
        } else if (k < len) {
            arrangeRight(a, p + 1, e, k);
        } else {
            arrangeRight(a, s, p - 1, k - len);
        }
    }
}

void QuickSort(int a[], int s, int e) {
    if (s < e) {
        int p = partition(a, s, e);
        QuickSort(a, s, p - 1);
        QuickSort(a, p + 1, e);
    }
}

int main() {
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> k;
    arrangeRight(arr, 0, n - 1, k);
    QuickSort(arr, n - k, n - 1);
    for (int i = n - 1; i >= n - k; --i) {
        cout << arr[i] << endl;
    }
    return 0;
}
