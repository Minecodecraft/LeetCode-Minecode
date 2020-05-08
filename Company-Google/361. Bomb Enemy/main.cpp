//
//  main.cpp
//  361. Bomb Enemy
//
//  Created by Jaylen Bian on 4/17/20.
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
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size(), m = n == 0 ? 0 : grid[0].size();
        int rowcnt = 0, res = 0;
        vector<int> colcnt (m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!j || grid[i][j-1] == 'W') {
                    rowcnt = 0;
                    for (int k = j; k < m && grid[i][k] != 'W'; ++k)
                        if (grid[i][k] == 'E') ++rowcnt;
                }
                if (!i || grid[i-1][j] == 'W') {
                    colcnt[j] = 0;
                    for (int k = i; k < n && grid[k][j] != 'W'; ++k)
                        colcnt[j] += grid[k][j] == 'E';
                }
                if (grid[i][j] == '0')
                    res = max(res, rowcnt + colcnt[j]);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
