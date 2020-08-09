//
//  main.cpp
//  296. Best Meeting Point
//
//  Created by Jaylen Bian on 8/8/20.
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

// Tips:
// This is a simpler version of the problem https://www.luogu.com.cn/problem/P2512

// Solution:
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> xs, ys;
        int n = grid.size(), m = n == 0 ? 0 : grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    xs.push_back(i);
                    ys.push_back(j);
                }
            }
        }
        sort(ys.begin(), ys.end());
        int x = xs[xs.size() / 2];
        int y = ys[ys.size() / 2];
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    res += abs(i - x);
                    res += abs(j - y);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> g = {
        {1,0,0,0,1},{0,0,0,0,0},{0,0,1,0,0}
    };
    int res = sol.minTotalDistance(g);
    cout << res << endl;
    return 0;
}
