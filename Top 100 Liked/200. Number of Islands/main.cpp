//
//  main.cpp
//  200. Number of Islands
//
//  Created by 边俊林 on 2019/10/17.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = rows ? grid[0].size(): 0;
        UnionFind(rows * cols);
        vector<bool> vis (rows * cols, false);

        queue<int> q;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int idx = row * cols + col;
                if (!vis[idx] && grid[row][col]=='1')
                    q.push(idx);

                while (q.size()) {
                    int point = q.front(); q.pop();
                    int currow = point / cols, curcol = point % cols;
                    for (int i = 0; i < 4; ++i) {
                        int nxtrow = currow + dir[i];
                        int nxtcol = curcol + dir[i+1];
                        int nxtidx = nxtrow * cols + nxtcol;
                        if (nxtrow>=0 && nxtrow<rows && nxtcol>=0 && nxtcol<cols
                            && !vis[nxtidx] && grid[nxtrow][nxtcol]=='1') {
                                Union(idx, nxtidx);
                                vis[nxtidx] = true;
                                q.push(nxtidx);
                        }
                    }
                }
            }
        }

        unordered_set<int> st;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == '1')
                    st.insert(Find(row * cols + col));
            }
        }
        return st.size();
    }

private:
    vector<int> p;
    vector<int> sz;
    int dir[5] = {0, 1, 0, -1, 0};

    void UnionFind(int capacity) {
        p = vector<int> (capacity);
        sz = vector<int> (capacity);
        for (int i = 0; i < capacity; ++i) p[i] = i;
    }

    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;

        if (sz[pu] >= sz[pv]) {
            p[pv] = pu;
            sz[pu] += sz[pv];
        } else {
            p[pu] = pv;
            sz[pv] += sz[pu];
        }
        return true;
    }

    int Find(int n) {
        while (p[n] != n) {
            p[n] = p[p[n]];
            n = p[n];
        }
        return n;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> mats = {
        "11110", "11010", "11000", "00000"
//        "11000", "11000", "00100", "00011"
    };

    vector<vector<char>> mat;
    for (auto& str: mats) {
        vector<char> arr;
        for (auto& ch: str) arr.push_back(ch);
        mat.push_back(arr);
    }
    int res = sol.numIslands(mat);
    cout << res << endl;
    return 0;
}
