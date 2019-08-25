//
//  main.cpp
//  174. Dungeon Game
//
//  Created by 边俊林 on 2019/8/25.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/dungeon-game/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size(), cols = dungeon[0].size();
        // dp[i][j] means the minimum hp value needed in grid[i][j]
        vector<vector<int>> dp (rows+1, vector<int> (cols+1, INT_MAX));
        dp[rows][cols-1] = dp[rows-1][cols] = 1;
        for (int row = rows-1; row >= 0; --row) {
            for (int col = cols-1; col >= 0; --col) {
                int oriVal = min(dp[row+1][col], dp[row][col+1]) - dungeon[row][col];
                dp[row][col] = oriVal <= 0 ? 1 : oriVal;
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> dungons = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
//    vector<vector<int>> dungons = {{100}};
    auto res = sol.calculateMinimumHP(dungons);
    cout << res << endl;
    return 0;
}
