//
//  main.cpp
//  778. Swim in Rising Water
//
//  Created by 边俊林 on 2019/10/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/swim-in-rising-water/
\* ------------------------------------------------------ */

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
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int maxval = INT_MIN;
        rows = grid.size(), cols = grid[0].size();
        for (int row = 0; row < rows; ++row)
            for (int col = 0; col < cols; ++col)
                maxval = max(maxval, grid[row][col]);
        int l = max(grid[0][0], grid[rows-1][cols-1]), r = maxval;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (check(grid, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int rows, cols;

    bool check(vector<vector<int>>& grid, int max) {
        if (grid[0][0] > max) return false;
        queue<pair<int, int>> Q;
        vector<vector<bool>> vis (rows, vector<bool> (cols, false));
        Q.push({0, 0});
        vis[0][0] = true;
        while (Q.size()) {
            auto cur = Q.front(); Q.pop();
            for (int i = 0; i < 4; ++i) {
                int toRow = cur.first + dx[i];
                int toCol = cur.second + dy[i];
                if (toRow == rows-1 && toCol == cols-1)
                    return true;
                if (toRow>=0 && toRow<rows && toCol>=0 && toCol<cols
                    && !vis[toRow][toCol] && grid[toRow][toCol] <= max) {
                    vis[toRow][toCol] = true;
                    Q.push({toRow, toCol});
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> grid = {
        {0, 2}, {1, 3}
    };
//    vector<vector<int>> grid = {
//        {0, 1, 2, 3, 4},
//        {24,23,22,21,5},
//        {12,13,14,15,16},
//        {11,17,18,19,20},
//        {10,9,8,7,6}
//    };
    int res = sol.swimInWater(grid);
    cout << res << endl;
    return 0;
}
