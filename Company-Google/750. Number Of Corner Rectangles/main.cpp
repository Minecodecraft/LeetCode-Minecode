//
//  main.cpp
//  750. Number Of Corner Rectangles
//
//  Created by Jaylen Bian on 10/4/20.
//  Copyright © 2020 边俊林. All rights reserved.
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
// Solution 1: Very bad solution
/*
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int n = grid.size(), m = n == 0 ? 0 : grid[0].size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!grid[i][j]) continue;
                for (int k = j + 1; k < m; ++k) {
                    if (!grid[i][k]) continue;
                    for (int l = i+1; l < n; ++l) {
                        if (grid[l][j] && grid[l][k])
                            ++res;
                    }
                }
            }
        }
        return res;
    }
};
 */

// Solution 2:
// Use map to save previous count
/*
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        unordered_map<int, int> count;
        int res = 0, n = grid.size(), m = n == 0 ? 0 : grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!grid[i][j]) continue;
                for (int k = j + 1; k < m; ++k) {
                    if (!grid[i][k]) continue;
                    int idx = j * 210 + k;
                    res += count[idx]++;
                }
            }
        }
        return res;
    }
};
 */

// Solution 3
// Optimize map unsage. Optimize the O(R*C*C) to O(N√N + R*C)
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int n = grid.size(), m = n == 0 ? 0 : grid[0].size();
        int res = 0, cnt = 0;

        vector<vector<int>> pos (n);
        unordered_map<int, int> count;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    pos[i].push_back(j);
                    ++cnt;
                }
            }
        }

        int threshold = sqrt(cnt);
        for (int i = 0; i < n; ++i) {
            if (pos[i].size() >= threshold) {
                unordered_set<int> match (pos[i].begin(), pos[i].end());
                for (int j = 0; j < n; ++j) {
                    if (j <= i && pos[j].size() >= threshold)
                        continue;
                    int matched = 0;
                    for (int k = 0; k < pos[j].size(); ++k) {
                        if (match.count(pos[j][k]))
                            ++matched;
                    }
                    res += matched * (matched - 1) / 2;
                }
            } else {
                for (int j = 0; j < m; ++j) {
                    if (!grid[i][j]) continue;
                    for (int k = j+1; k < m; ++k) {
                        if (!grid[i][k]) continue;
                        int idx = j * 210 + k;
                        res += count[idx]++;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> arr = {
        {0,1,0},{1,0,1},{1,0,1},{0,1,0}
    };
    int res = sol.countCornerRectangles(arr);
    cout << res << endl;
    return 0;
}
