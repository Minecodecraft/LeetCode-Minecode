//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2020/1/12.
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;

        fa = vector<int> (n, 0);
        for (int i = 0; i < n; ++i) fa[i] = i;
        sz = n;
        for (auto& conn: connections)
            Union(conn[0], conn[1]);

        return sz-1;
    }

private:
    vector<int> fa;
    int sz;

    bool Union(int u, int v) {
        int pu = Find(u), pv = Find(v);
        if (pu == pv) return false;
        fa[pu] = pv;
        --sz;
        return true;
    }

    int Find(int u) {
        if (u == fa[u]) return u;
        return fa[u] = Find(fa[u]);
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> conn = {
        {0, 1}, {0, 2}, {1, 2}
    };
    int n = 4;
    int res = sol.makeConnected(n, conn);
    cout << res << endl;
    return 0;
}
