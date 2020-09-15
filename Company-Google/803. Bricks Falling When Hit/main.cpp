//
//  main.cpp
//  803. Bricks Falling When Hit
//
//  Created by Jaylen Bian on 9/13/20.
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
    vector<int> f;
    vector<int> sz;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    void UnionFind(int capacity) {
        f = vector<int>(capacity, 0);
        sz = vector<int>(capacity, 1);
        for (int i = 0 ; i < capacity; ++i)
            f[i] = i;
    }

    void Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return;
        f[pv] = pu;
        sz[pu] += sz[pv];
    }

    int Find(int u) {
        if (f[u] != u) f[u] = Find(f[u]);
        return f[u];
    }

    int bricks() {
        return sz[Find(sz.size()-1)] - 1;
    }

public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> g = vector<vector<int>> (n, vector<int> (m));
        for (int i = 0; i < n; ++i)
            g[i] = vector<int>(grid[i].begin(), grid[i].end());
        for (auto hit: hits)
            g[hit[0]][hit[1]] = 0;

        UnionFind(n * m + 1);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (g[r][c]) {
                    int idx = r * m + c;
                    if (r == 0)
                        Union(idx, n*m);
                    if (r > 0 && g[r-1][c])
                        Union(idx, (r-1) * m + c);
                    if (c > 0 && g[r][c-1])
                        Union(idx, r * m + c - 1);
                }
            }
        }

        int t = hits.size()-1;
        vector<int> res (t+1);

        while (t >= 0) {
            int r = hits[t][0], c = hits[t][1];
            if (grid[r][c]) {
                int prebricks = bricks();
                int idx = r * m + c;
                for (int k = 0; k < 4; ++k) {
                    int tx = r + dx[k], ty = c + dy[k];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m && g[tx][ty]) {
                        Union(idx, tx * m + ty);
                    }
                }
                if (r == 0)
                    Union(idx, n * m);
                g[r][c] = 1;
                res[t] = max(0, bricks() - prebricks - 1);
            }
            --t;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> grid = {
        {1,0,0,0}, {1,1,1,0}
//        {0,1,1,1,1},{1,1,1,1,0},{1,1,1,1,0},{0,0,1,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}
    };
    vector<vector<int>> hits = {
        {1, 0}
//        {6,0},{1,0},{4,3},{1,2},{7,1},{6,3},{5,2},{5,1},{2,4},{4,4},{7,3}
    };
    auto res = sol.hitBricks(grid, hits);
    for_each(res.begin(), res.end(), [](int ele) { cout << ele << ", ";  });
    return 0;
}
