/**
 * @BelongsProject: NOI
 * @Author: yuan wang
 * @CreateTime: 2023-08-13  17:01
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void arrangeRight(int *a, int s, int e, int k) {
    if (s >= e) {
        return;
    }
    int key = a[s];
    int i = s, j = e;
    while (i != j) {
        while (j > i && a[j] >= key) {
            --j;
        }
        swap(a[i], a[j]);
        while (i < j && a[i] <= key) {
            ++i;
        }
        swap(a[i], a[j]);
    }
    if (i == k) {
        return;
    } else if (i < k) {
        arrangeRight(a, i + 1, e, k);
    } else {
        arrangeRight(a, 0, j - 1, k);
    }
}

void QuickSort(int a[], int s, int e) {
    if (s >= e) {
        return;
    }
    int k = a[s];
    int i = s, j = e;
    while (i != j) {
        while (j > i && a[j] >= k) {
            --j;
        }
        swap(a[i], a[j]);//经过奇数次交换
        while (i < j && a[i] <= k) {
            ++i;
        }
        swap(a[i], a[j]);//经过偶数次交换
    }//处理完后，a[i] = k
    QuickSort(a, s, i - 1);
    QuickSort(a, i + 1, e);
}

/**
 * @description: 输出前 k 大的数
 * @author: yuan wang
 * @date: 2023/08/13 17:01
 * @param: null
 * @return: null
 */
int main() {
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> k;
    arrangeRight(arr, 0, n - 1, k);
    QuickSort(arr, n - k, n - 1);
    for (int i = n - 1; i >= n - k; --i) {
        cout << arr[i] << endl;
    }
    delete[]arr;
    return 0;
}
