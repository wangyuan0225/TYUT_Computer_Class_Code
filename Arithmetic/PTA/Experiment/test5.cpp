/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : test5.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2023-12-01  23:35
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    double density;
};

bool compare(Item a, Item b) {
    return a.density > b.density;
}

vector<Item> items;
vector<int> solution;
int n, c, maxValue = 0;

void backtrack(int index, int currentWeight, int currentValue, int remainValue) {
    if (index == n || currentWeight == c || currentValue + remainValue <= maxValue) {
        return;
    }
    if (currentWeight + items[index].weight <= c) {
        solution.push_back(index);
        maxValue = max(maxValue, currentValue + items[index].value);
        backtrack(index + 1, currentWeight + items[index].weight, currentValue + items[index].value, remainValue - items[index].value);
        solution.pop_back();
    }
    backtrack(index + 1, currentWeight, currentValue, remainValue - items[index].value);
}

int main() {
    cin >> n >> c;
    items.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].density = (double)items[i].value / items[i].weight;
    }
    sort(items.begin(), items.end(), compare);
    int remainValue = 0;
    for (int i = 0; i < n; i++) {
        remainValue += items[i].value;
    }
    backtrack(0, 0, 0, remainValue);
    cout << maxValue << endl;
    return 0;
}