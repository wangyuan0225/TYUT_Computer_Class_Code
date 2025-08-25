/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : LeetCode
  * @File           : 0054.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2025/4/1 23:25
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return {};
		}

		int rows = matrix.size(), columns = matrix[0].size();
		vector<vector<bool>> visited(rows, vector<bool>(columns));
		int total = rows * columns;
		vector<int> order(total);

		int row = 0, column = 0;
		int directionIndex = 0;
		for (int i = 0; i < total; i++) {
			order[i] = matrix[row][column];
			visited[row][column] = true;
			int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
			if (nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
				directionIndex = (directionIndex + 1) % 4;
			}
			row += directions[directionIndex][0];
			column += directions[directionIndex][1];
		}
		return order;
	}
};

int main() {
	vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Solution s;
	vector<int> order = s.spiralOrder(matrix);
	for (int i = 0; i < order.size(); i++) {
		cout << order[i] << " ";
	}
    return 0;
}
