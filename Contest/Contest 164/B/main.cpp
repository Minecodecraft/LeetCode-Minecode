//
//  main.cpp
//  Contest 164
//
//  Created by 边俊林 on 2019/11/24.
//  Copyright © 2019 边俊林. All rights reserved.
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
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = n ? grid[0].size() : 0;
        vector<vector<bool>> vis (n, vector<bool> (m, false));

        int res = 0;
        for (int r = 0; r < n; ++r) {
            int cnt = 0;
            for (int c = 0; c < m; ++c)
                if (grid[r][c] == 1) ++cnt;
            if (cnt >= 2) {
                for (int c = 0; c < m; ++c)
                    if (grid[r][c] == 1 && !vis[r][c]) {
                        ++res;
                        vis[r][c] = true;
                    }
            }
        }

        for (int c = 0; c < m; ++c) {
            int cnt = 0;
            for (int r = 0; r < n; ++r)
                if (grid[r][c] == 1) ++cnt;
            if (cnt >= 2) {
                for (int r = 0; r < n; ++r)
                    if (grid[r][c] == 1 && !vis[r][c]) {
                        ++res;
                        vis[r][c] = true;
                    }
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
//        {1, 0}, {0, 1}
//        {1, 0}, {1, 1}
    };
    int res = sol.countServers(mat);
    cout << res << endl;
    return 0;
}
