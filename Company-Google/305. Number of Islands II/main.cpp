//
//  main.cpp
//  305. Number of Islands II
//
//  Created by Jaylen Bian on 10/17/20.
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
// Solution 1
/*
class Solution {
    vector<int> f;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int Find(int u) {
        if (f[u] == u) return u;
        return f[u] = Find(f[u]);
    }

public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& poss) {
        f = vector<int> (m*n, -1);

        vector<int> res;
        int cnt = 0;
        for (auto& pos: poss) {
            int x = pos[0], y = pos[1], idx = x * n + y;
            if (f[idx] != -1) {
                res.push_back(cnt);
                continue;
            }
            f[idx] = idx;
            ++cnt;
            for (int i = 0; i < 4; ++i) {
                int tx = x + dx[i], ty = y + dy[i], newidx = tx * n + ty;
                if (tx >= 0 && tx < m && ty >= 0 && ty < n && f[newidx] != -1) {
                    int pidx = Find(idx), newpidx = Find(newidx);
                    if (pidx != newpidx) {
                        f[newpidx] = pidx;
                        --cnt;
                    }
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};
 */

// Solution 2
// Use rank to optimize
class Solution {
    vector<int> f, rank;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int Find(int u) {
        if (f[u] == u) return u;
        return f[u] = Find(f[u]);
    }

    bool Union(int u, int v) {
        int pu = Find(u), pv = Find(v);
        if (pu == pv)
            return false;

        if (rank[pu] == rank[pv]) {
            f[pu] = pv;
            ++rank[pv];
        } else if (rank[pu] > rank[pv]) {
            f[pv] = pu;
        } else {
            f[pu] = pv;
        }
        return true;
    }

public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& poss) {
        f = vector<int> (m*n, -1);
        rank = vector<int> (m*n, 0);

        vector<int> res;
        int cnt = 0;
        for (auto& pos: poss) {
            int x = pos[0], y = pos[1], idx = x * n + y;
            if (f[idx] != -1) {
                res.push_back(cnt);
                continue;
            }
            f[idx] = idx;
            ++cnt;
            for (int i = 0; i < 4; ++i) {
                int tx = x + dx[i], ty = y + dy[i], newidx = tx * n + ty;
                if (tx >= 0 && tx < m && ty >= 0 && ty < n && f[newidx] != -1) {
                    if (Union(idx, newidx))
                        --cnt;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};

int main() {

    return 0;
}
