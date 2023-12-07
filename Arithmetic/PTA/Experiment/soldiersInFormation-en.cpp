/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : soldiersInFormation.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : On a playground divided into a grid, n soldiers are scattered on the
  *                     grid points. The grid points are represented by integer coordinates
  *                     (x, y).Soldiers can move one step up, down, left, or right along the
  *                     grid edges, but only one soldier can be on a grid point at the same
  *                     time.According to the command of the officer, the soldiers are to be
  *                     arranged in a horizontal queue, i.e., arranged as (x, y),(x+1,y),…,
  *                     (x+n-1,y).How to choose the values of x and y to minimize the total
  *                     number of steps required for the soldiers to form a row. Write a
  *                     program to calculate the minimum number of steps required for all
  *                     soldiers to form a row.
  * @Attention      : Input format:
  *                     The first line is the number of soldiers n, 1≤n≤10000. The next n lines
  *                     are the initial positions of the soldiers, each line contains 2 integers
  *                     x and y, -10000≤x, y≤10000.
  *                   Output format:
  *                     Print the minimum number of steps required for the soldiers to form a row.
  * @Date           : 2023-12-02  20:02
  * @Version        : 2.0 Added comments for key statements and introduced the use of divide and
  *                     conquer strategy, reflected in the quicksort.
  *                   3.0 Changed quicksort to mergesort.
  ****************************************************************************************
  */

#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Merge two sorted arrays
 * @param a
 * @param s
 * @param m
 * @param e
 * @param tmp
 */
void Merge(int a[], int s, int m, int e, int tmp[]) {
    int pb = 0;
    int p1 = s, p2 = m + 1;
    while (p1 <= m && p2 <= e) {
        if (a[p1] < a[p2]) {
            tmp[pb++] = a[p1++];
        } else {
            tmp[pb++] = a[p2++];
        }
    }
    while (p1 <= m)
        tmp[pb++] = a[p1++];
    while (p2 <= e)
        tmp[pb++] = a[p2++];
    for (int i = 0; i < e - s + 1; ++i)
        a[s + i] = tmp[i];
}

/**
 * Merge sort
 * @param a
 * @param s
 * @param e
 * @param tmp
 */
void MergeSort(int a[], int s, int e, int tmp[]) {
    if (s < e) {
        int m = s + (e - s) / 2;
        MergeSort(a, s, m, tmp);
        MergeSort(a, m + 1, e, tmp);
        Merge(a, s, m, e, tmp);
    }
}

int main() {
    int n;
    cin >> n;
    int *x = new int[n];
    int *y = new int[n];
    int *tmp = new int[n];

    // Read the initial positions of each soldier
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Use mergesort to sort x and y separately
    MergeSort(x, 0, n - 1, tmp);
    MergeSort(y, 0, n - 1, tmp);

    // Subtract i from each sorted x in order
    for (int i = 1; i <= n; ++i) {
        x[i] -= i;
    }

    // Merge sort the sorted x again
    MergeSort(x, 0, n - 1, tmp);

    int rex, rey;

    // If n is even, take the average of the middle two points in the sorted array as the median
    if (n % 2 == 0) {
        rex = (x[n / 2 - 1] + x[n / 2]) / 2;
        rey = (y[n / 2 - 1] + y[n / 2]) / 2;
    } else { // If n is odd, the middle point in the sorted array is the median
        rex = x[n / 2];
        rey = y[n / 2];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(x[i] - rex) + abs(y[i] - rey);
    }

    // Print the result
    cout << sum << endl;

    delete[] x;
    delete[] y;
    delete[] tmp;
    return 0;
}