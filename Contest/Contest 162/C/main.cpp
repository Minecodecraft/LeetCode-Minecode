//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/11/10.
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
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = n ? grid[0].size() : 0;
        UnionFind(n * m);

        vector<vector<bool>> vis (n, vector<bool> (m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    dfs(vis, i, j, n, m, grid);
                }
            }
        }

        unordered_set<int> ignore;
        for (int i = 0; i < m; ++i) {
            ignore.insert(Find(i));
            ignore.insert(Find((n-1)*m + i));
        }
        for (int i = 0; i < n; ++i) {
            ignore.insert(Find(i*m));
            ignore.insert(Find(i*m+m-1));
        }

        unordered_set<int> res;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    int p = Find(i * m + j);
                    if (ignore.count(p) == 0)
                        res.insert(p);
                }
            }
        }
        return res.size();
    }

private:
    vector<int> f;
    int dir[5] = {0, 1, 0, -1, 0};

    void dfs(vector<vector<bool>>& vis, int x, int y, int n, int m, vector<vector<int>>& grid) {
        if (vis[x][y]) return;
        vis[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dir[i];
            int ty = y + dir[i+1];
            if (tx>=0 && tx<n && ty>=0 && ty<m && !vis[tx][ty] && grid[tx][ty] == 0) {
                Union(x*m+y, tx*m+ty);
                dfs(vis, tx, ty, n, m, grid);
            }
        }
    }

    void UnionFind(int capacity) {
        f = vector<int> (capacity);
        for (int i = 0; i < capacity; ++i)
            f[i] = i;
    }

    bool Union(int u, int v) {
        int p1 = Find(u);
        int p2 = Find(v);

        if (p1 == p2)
            return false;
        f[p1] = p2;
        // TODO: Use Weighted Union-find
        return true;
    }

    int Find(int u) {
        if (f[u] == u)
            return u;
        return f[u] = Find(f[u]);
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
//        {1,1,1,1,1,1,1,0},
//        {1,0,0,0,0,1,1,0},
//        {1,0,1,0,1,1,1,0},
//        {1,0,0,0,0,1,0,1},
//        {1,1,1,1,1,1,1,0}

//        {0,0,1,0,0},
//        {0,1,0,1,0},
//        {0,1,1,1,0}

        {1,1,1,1,1,1,1},
        {1,0,0,0,0,0,1},
        {1,0,1,1,1,0,1},
        {1,0,1,0,1,0,1},
        {1,0,1,1,1,0,1},
        {1,1,1,1,1,1,1},
        {1,0,0,0,0,0,1},
    };
    int res = sol.closedIsland(mat);
    cout << res << endl;
    return 0;
}
