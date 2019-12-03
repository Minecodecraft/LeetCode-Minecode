//
//  main.cpp
//  959. Regions Cut By Slashes
//
//  Created by 边俊林 on 2019/12/3.
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
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        tot = 4 * n * n;
        UnionFind(tot);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != '/') {
                    Union(idx(i, j, 0), idx(i, j, 1));
                    Union(idx(i, j, 2), idx(i, j, 3));
                }
                if (grid[i][j] != '\\') {
                    Union(idx(i, j, 0), idx(i, j, 3));
                    Union(idx(i, j, 1), idx(i, j, 2));
                }
                if (i > 0)
                    Union(idx(i-1, j, 1), idx(i, j, 3));
                if (j > 0)
                    Union(idx(i, j-1, 2), idx(i, j, 0));
            }
        }
        return _sz;
    }

private:
    vector<int> fa;
    int n, tot;
    int _sz;

    int idx(int x, int y, int sub) {
        return (x * n + y) * 4 + sub;
    }

    void UnionFind(int sz) {
        fa = vector<int> (sz, 0);
        for (int i = 0; i < sz; ++i) fa[i] = i;
        _sz = sz;
    }

    void Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu != pv) {
            fa[pu] = pv;
            --_sz;
        }
    }

    int Find(int u) {
        if (fa[u] == u) return u;
        return fa[u] = Find(fa[u]);
    }
};

int main() {
    Solution sol = Solution();
    vector<string> g = {
        "\\/",
        "/\\"
    };
    int res = sol.regionsBySlashes(g);
    cout << res << endl;
    return 0;
}
