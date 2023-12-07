/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : 0-1backpack.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 给定n(n<=100)种物品和一个背包。物品i的重量是wi(wi<=100)，价值为vi(vi<=100)，
  *                     背包的容量为C(C<=1000)。应如何选择装入背包中的物品，使得装入背包中物品的总价值
  *                     最大? 在选择装入背包的物品时，对每种物品i只有两个选择：装入或不装入。不能将物品
  *                     i装入多次，也不能只装入部分物品i。
  * @Attention      : 输入格式:
  *                     共有n+1行输入：第一行为n值和c值，表示n件物品和背包容量c；接下来的n行，每行有两
  *                     个数据，分别表示第i(1≤i≤n)件物品的重量和价值。
  *                   输出格式:
  *                     输出装入背包中物品的最大总价值。
  * @Date           : 2023-12-02  10:53
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义物品结构体，包含物品的重量和价值
struct Item {
    int weight;
    int value;
};

//自定义比较函数，按照价值/重量的比例对物品进行排序
struct compare {
    bool operator()(const Item& a, const Item& b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }
};

/**
 * 定义限界函数，计算当前解的上界
 * @param capacity
 * @param items
 * @param current
 * @return
 */
double bound(int capacity, vector<Item>& items, int current) {
    double result = 0.0;
    // 遍历剩余的物品
    for (int i = current; i < items.size(); i++) {
        // 如果背包的剩余容量大于等于当前物品的重量，就把当前物品装入背包
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            result += items[i].value;
        } else {
            // 如果背包的剩余容量小于当前物品的重量，就按照价值/重量的比例把当前物品的一部分装入背包
            result += (double)items[i].value / items[i].weight * capacity;
            break;
        }
    }
    return result;
}

/**
 * 定义回溯函数，搜索所有可能的解
 * @param capacity
 * @param items
 * @param current
 * @param value
 * @param best
 */
void knapsack(int capacity, vector<Item>& items, int current, int value, int& best) {
    // 如果已经考虑了所有的物品，就更新最优解
    if (current == items.size()) {
        best = max(best, value);
        return;
    }
    // 如果当前的解加上剩余物品的最大可能价值仍然小于等于最优解，就剪枝
    if (value + bound(capacity, items, current) <= best) {
        return;
    }
    // 如果背包的剩余容量大于等于当前物品的重量，就尝试把当前物品装入背包
    if (capacity >= items[current].weight) {
        knapsack(capacity - items[current].weight, items, current + 1, value + items[current].value, best);
    }
    // 不论背包的剩余容量是否大于等于当前物品的重量，都尝试不把当前物品装入背包
    knapsack(capacity, items, current + 1, value, best);
}

int main() {
    int n, c;
    // 读取物品的数量和背包的容量
    cin >> n >> c;
    vector<Item> items(n);
    // 读取每个物品的重量和价值
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }
    // 按照价值/重量的比例对物品进行排序
    sort(items.begin(), items.end(), compare());
    int best = 0;
    // 使用回溯法来找到最优解
    knapsack(c, items, 0, 0, best);
    // 输出最优解
    cout << best << endl;
    return 0;
}