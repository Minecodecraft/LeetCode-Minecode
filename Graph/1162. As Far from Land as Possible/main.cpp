//
//  main.cpp
//  1162. As Far from Land as Possible
//
//  Created by 边俊林 on 2019/12/10.
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
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)
                if (grid[r][c] == 1) q.push({r, c});
        int cover = q.size(), steps = 1, res = 0;
        vector<int> dir = {1, 0, -1, 0, 1};
        while (q.size()) {
            int sz = q.size();
            ++steps;
            while (sz--) {
                int r = q.front().first, c = q.front().second;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int tr = r + dir[i], tc = c + dir[i+1];
                    if (tr>=0 && tr<n && tc>=0 && tc<n && grid[tr][tc] == 0) {
                        ++cover;
                        grid[tr][tc] = steps;
                        res = max(res, steps);
                        q.push({tr, tc});
                    }
                }
            }
        }
        
        return cover == n*n ? res-1 : -1;
    }
};

int main() {

    return 0;
}
