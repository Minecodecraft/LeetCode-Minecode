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
// Use map
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

int main() {

    return 0;
}
