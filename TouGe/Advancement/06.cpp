/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : Advancement
  * @File           : 06.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/28 15:48
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int total_sum = 0;
int target_sum;
int min_count = INT_MAX;

bool dfs(int x, int y, int current_sum, int count) {
    if (current_sum == target_sum) {
        min_count = min(min_count, count);
        return true;
    }

    if (current_sum > target_sum) {
        return false;
    }

    visited[x][y] = true;
    bool found = false;

    const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (const auto& dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
            found |= dfs(nx, ny, current_sum + grid[nx][ny], count + 1);
        }
    }

    visited[x][y] = false;
    return found;
}

int main() {
    cin >> m >> n;
    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            total_sum += grid[i][j];
        }
    }

    if (total_sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    target_sum = total_sum / 2;

    if (dfs(0, 0, grid[0][0], 1)) {
        cout << min_count << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
