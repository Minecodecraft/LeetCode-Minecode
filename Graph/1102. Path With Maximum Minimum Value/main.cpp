//
//  main.cpp
//  1102. Path With Maximum Minimum Value
//
//  Created by 边俊林 on 2019/12/8.
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
    int maximumMinimumPath(vector<vector<int>>& A) {
        int rows = A.size(), cols = rows ? A[0].size() : 0;
        int tot = rows * cols;
        vector<Vertex> vtxs;
        fa = vector<int> (tot);
        vector<vector<bool>> vis (rows, vector<bool> (cols, false));
        for (int i = 0; i < tot; ++i) fa[i] = i;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                vtxs.push_back(Vertex(A[r][c], r, c));
            }
        }
        sort(vtxs.begin(), vtxs.end(), [](Vertex& a, Vertex& b) {
            return a.val > b.val;
        });

        int idx = 0, res = vtxs[idx].val;
        while (Find(0) != Find(tot-1)) {
            int p = idx;
            while (p < tot && vtxs[p].val == vtxs[idx].val) {
                int x = vtxs[p].x, y = vtxs[p].y;
                for (int i = 0; i < 4; ++i) {
                    int tx = x + dir[i];
                    int ty = y + dir[i+1];
                    if (tx>=0 && tx<rows && ty>=0 && ty<cols && vis[tx][ty])
                        Union(x*cols+y, tx*cols+ty);
                }
                vis[x][y] = true;
                ++p;
            }
            res = vtxs[idx].val;
            idx = p;
        }
        return res;
    }

private:
    struct Vertex {
        int val, x, y;
        Vertex(int v, int x, int y)
        : val(v), x(x), y(y) { }
    };

    vector<int> fa;
    vector<int> dir = {1, 0, -1, 0, 1};

    void Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu != pv)
            fa[pu] = pv;
    }

    int Find(int u) {
        if (fa[u] == u) return u;
        return fa[u] = Find(fa[u]);
    }
};

int main() {

    return 0;
}
