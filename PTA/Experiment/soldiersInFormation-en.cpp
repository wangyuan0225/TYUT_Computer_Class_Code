/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : CPPExperiment
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
  *                   4.0 Changed mergesort to quickSelect. Thus, the true spirit of the divide
  *                     and conquer algorithm can be fully embodied.
  ****************************************************************************************
  */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * \brief Partition the array into two parts, the left part is less than the pivot,
 * \param nums The array to be partitioned
 * \param low The lower bound of the array
 * \param high The upper bound of the array
 * \return The index of the pivot
 */
int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low;
    for (int j = low; j < high; ++j) {
        if (nums[j] < pivot) {
            swap(nums[i], nums[j]);
            ++i;
        }
    }
    swap(nums[i], nums[high]);
    return i;
}

/**
 * \brief Find the kth smallest element in the array
 * \param nums The array to be partitioned
 * \param low The lower bound of the array
 * \param high The upper bound of the array
 * \param k The index of the kth smallest element
 * \return The kth smallest element
 */
int quickSelect(vector<int>& nums, int low, int high, int k) {
    if (low == high) return nums[low];
    int pi = partition(nums, low, high);
    if (k == pi)
        return nums[pi];
    if (k < pi)
        return quickSelect(nums, low, pi - 1, k);
    return quickSelect(nums, pi + 1, high, k);
}

int findMedian(vector<int>& nums) {
    int n = nums.size();
    return quickSelect(nums, 0, n - 1, n / 2);
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    vector<int> tmp(n);

    // Read the initial positions of each soldier
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());

    // Subtract i from each sorted x in order
    for (int i = 0; i < n; ++i) {
        x[i] -= i;
    }

    int rex = findMedian(x);
    int rey = findMedian(y);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(x[i] - rex) + abs(y[i] - rey);
    }

    // Print the result
    cout << sum << endl;

    return 0;
}
