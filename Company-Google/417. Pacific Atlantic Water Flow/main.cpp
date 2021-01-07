//
//  main.cpp
//  417. Pacific Atlantic Water Flow
//
//  Created by Jaylen Bian on 1/7/21.
//  Copyright © 2021 边俊林. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
// Solution 1: BFS
/*
class Solution {
    vector<int> dir = {0, 1, 0, -1, 0};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q1, q2;
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
        vector<vector<bool>> vis;
        vector<vector<bool>> can1 (m, vector<bool> (n, false));
        vector<vector<bool>> can2 (m, vector<bool> (n, false));

        vis = vector<vector<bool>> (m, vector<bool> (n, false));
        for (int i = 0; i < m; ++i) {
            q1.push({i, 0});
            q2.push({i, n-1});
        }
        for (int i = 0; i < n; ++i) {
            q1.push({0, i});
            q2.push({m-1, i});
        }
        while (q1.size()) {
            auto pt = q1.front();
            q1.pop();
            if (vis[pt.first][pt.second]) continue;

            vis[pt.first][pt.second] = true;
            can1[pt.first][pt.second] = true;
            for (int i = 0; i < 4; ++i) {
                int dx = pt.first + dir[i], dy = pt.second + dir[i+1];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && matrix[dx][dy] >= matrix[pt.first][pt.second])
                    q1.push({dx, dy});
            }
        }

        vis = vector<vector<bool>> (m, vector<bool> (n, false));
        while (q2.size()) {
            auto pt = q2.front();
            q2.pop();
            if (vis[pt.first][pt.second]) continue;

            vis[pt.first][pt.second] = true;
            can2[pt.first][pt.second] = true;
            for (int i = 0; i < 4; ++i) {
                int dx = pt.first + dir[i], dy = pt.second + dir[i+1];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && matrix[dx][dy] >= matrix[pt.first][pt.second])
                    q2.push({dx, dy});
            }
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (can1[i][j] && can2[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};
 */

// Solution 2: DFS
class Solution {
    vector<vector<int>> vis, res;
    vector<int> dir = {0, 1, 0, -1, 0};
    void dfs(vector<vector<int>>& mat, int x, int y, int pre, int type) {
        if (x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size() || mat[x][y] < pre || vis[x][y] == 3 || vis[x][y] == type)
            return;
        vis[x][y] += type;
        if (vis[x][y] == 3)
            res.push_back({x, y});
        for (int i = 0; i < 4; ++i) {
            int dx = x + dir[i], dy = y + dir[i+1];
            dfs(mat, dx, dy, mat[x][y], type);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int m = mat.size(), n = m == 0 ? 0 : mat[0].size();
        vis = vector<vector<int>> (m, vector<int> (n, 0));
        for (int i = 0; i < m; ++i) {
            dfs(mat, i, 0, INT_MIN, 1);
            dfs(mat, i, n-1, INT_MIN, 2);
        }
        for (int i = 0; i < n; ++i) {
            dfs(mat, 0, i, INT_MIN, 1);
            dfs(mat, m-1, i, INT_MIN, 2);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> arr = {
        {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}
    };
    auto res = sol.pacificAtlantic(arr);
    cout << res.size() << endl;
    return 0;
}
