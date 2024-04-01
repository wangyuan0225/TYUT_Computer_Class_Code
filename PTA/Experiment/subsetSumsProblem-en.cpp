/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : CPPExperiment
  * @File           : subsetSumsProblem.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : Given a set S={x1,x2,…,xn} of positive integers and a positive
  *                     integer c,the subset sum problem is to determine whether there
  *                     exists a subset S1 of S such that the sum of elements in S1 equals
  *                     c. This code designs a backtracking method to solve the subset sum
  *                     problem and outputs the first solution found in the search tree
  *                     (established in input order).
  * @Attention      : Input format:
  *                     The first line of input contains two positive integers n and c,
  *                     where n represents the size of set S, and c is the target sum of
  *                     the subset. The following line contains n positive integers,
  *                     representing the elements of set S.
  *                   Output format:
  *                     Outputs the first solution found using backtracking, separated by
  *                     spaces, and a space after the last output. Outputs "No Solution!"
  *                     when there is no solution.
  * @Date           : 2023-12-02  09:16
  * @Version        : 2.0  Added the remaining boundary function, successfully passed
  *                         the last test point, no longer exceeding the time limit.
  ****************************************************************************************
  */

#include <iostream>
#include <vector>

using namespace std;

int n, c; // n: size of set S, c: target sum
bool found = false; // Flag to indicate if a solution is found

/**
 * Backtracking function
 * @param S Set of integers
 * @param solution Current solution vector
 * @param sum Current sum of the subset
 * @param index Current index in the set
 * @param remaining Sum of remaining elements in the set
 */
void backtrack(vector<int> &S, vector<int> &solution, int sum, int index, int remaining) {
    // Exit the recursion if a solution is already found
    if (found) return;

    // Check if a solution is found or if it's impossible to reach the target sum
    if (sum == c || sum + remaining < c) {
        if (sum == c) {
            found = true;
            for (int i = 0; i < solution.size(); i++) {
                if (solution[i] == 0) continue;
                cout << solution[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    // Constraint: stop if the sum exceeds the target or if all elements are processed
    if (sum > c || index == n) return;

    // Explore left subtree: include the current element
    solution[index] = S[index];
    backtrack(S, solution, sum + S[index], index + 1, remaining - S[index]);

    // Explore right subtree: exclude the current element
    solution[index] = 0;
    backtrack(S, solution, sum, index + 1, remaining - S[index]);
}

int main() {
    cin >> n >> c;
    vector<int> S(n), solution;
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> S[i];
        // Calculate total sum of the set
        totalSum += S[i];
    }
    backtrack(S, solution, 0, 0, totalSum);
    if (!found) {
        // Output if no solution is found
        cout << "No Solution!" << endl;
    }
    return 0;
}
