/****************************************************************************************
 * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
 * @BelongsProject: CPPExperiment
 * @File: 0-1backpack.cpp
 * @Author: Yuan Wang (wy0225)
 * @Brief: Given n (n<=100) items and a backpack. The weight of item i is wi (wi<=100),
 *         and its value is vi (vi<=100), with the backpack's capacity being C (C<=1000).
 *         How should one choose the items to put into the backpack so that the total value
 *         of the items in the backpack is maximized? When selecting items for the backpack,
 *         each item i has only two choices: to be included or not. Item i cannot be placed
 *         multiple times, nor can only a part of item i be placed.
 * @Attention: Input format:
 *             There are n+1 lines of input: The first line contains the values of n and c,
 *             representing the number of items and the capacity of the backpack respectively;
 *             the following n lines each contain two pieces of data, representing the weight
 *             and value of the ith (1≤i≤n) item.
 *             Output format:
 *             Output the maximum total value of the items in the backpack.
 * @Date: December 2, 2023, 10:53
 * @Version: 2.0  Added comments for key statements, and added the bounding function.
 ****************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure for items, including the weight and value of the item
struct Item {
    int weight;
    int value;
};

// Custom comparison function to sort items by value-to-weight ratio
struct compare {
    bool operator()(const Item& a, const Item& b) const {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }
};

/**
 * Define a bounding function to calculate the upper bound of the current solution
 * @param capacity - the remaining capacity of the knapsack
 * @param items - vector of items
 * @param current - index of the current item being considered
 * @return the maximum possible value that can be achieved with the remaining capacity
 */
double bound(int capacity, vector<Item>& items, int current) {
    double result = 0.0;
    // Iterate through the remaining items
    for (int i = current; i < items.size(); i++) {
        // If the remaining capacity of the knapsack is greater than or equal to the weight of the current item, add the item to the knapsack
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            result += items[i].value;
        } else {
            // If the remaining capacity is less than the weight of the current item, add a fraction of the item to the knapsack
            result += (double)items[i].value / items[i].weight * capacity;
            break;
        }
    }
    return result;
}

/**
 * Backtracking function to explore all possible solutions
 * @param capacity - the remaining capacity of the knapsack
 * @param items - vector of items
 * @param current - index of the current item being considered
 * @param value - the current total value of items in the knapsack
 * @param best - reference to the best solution found so far
 */
void knapsack(int capacity, vector<Item>& items, int current, int value, int& best) {
    // If all items have been considered, update the best solution
    if (current == items.size()) {
        best = max(best, value);
        return;
    }
    // Prune the branch if the current value plus the maximum possible value of remaining items is less than or equal to the best solution
    if (value + bound(capacity, items, current) <= best) {
        return;
    }
    // Try to add the current item to the knapsack if the remaining capacity is sufficient
    if (capacity >= items[current].weight) {
        knapsack(capacity - items[current].weight, items, current + 1, value + items[current].value, best);
    }
    // Explore the possibility of not adding the current item to the knapsack
    knapsack(capacity, items, current + 1, value, best);
}

int main() {
    int n, c;
    // Read the number of items and the capacity of the knapsack
    cin >> n >> c;
    vector<Item> items(n);
    // Read the weight and value of each item
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }
    // Sort the items by their value-to-weight ratio
    sort(items.begin(), items.end(), compare());
    int best = 0;
    // Use the backtracking approach to find the optimal solution
    knapsack(c, items, 0, 0, best);
    // Output the optimal solution
    cout << best << endl;
    return 0;
}
