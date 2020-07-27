//
//  main.cpp
//  947. Most Stones Removed with Same Row or Column
//
//  Created by Jaylen Bian on 7/27/20.
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
// Solution 1: DFS O(n^2), not so good
/*
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int g[n][n];
        memset(g, 0, n * n * sizeof(int));

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    g[i][++g[i][0]] = j;
                    g[j][++g[j][0]] = i;
                }
            }
        }
        int res = 0;
        vector<bool> vis (n, false);
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            stack<int> st;
            vis[i] = true;
            res--;
            st.push(i);
            while (st.size()) {
                res++;
                int cur = st.top(); st.pop();
                for (int j = 1; j <= g[cur][0]; ++j) {
                    int nxt = g[cur][j];
                    if (!vis[nxt]) {
                        st.push(nxt);
                        vis[nxt] = true;
                    }
                }
            }
        }
        return res;
    }
};
 */

// Solution 2: Union-find
class Solution {
    vector<int> p;

    void Union(int u, int v) {
        p[Find(u)] = Find(v);
    }

    int Find(int u) {
        if (p[u] != u) p[u] = Find(p[u]);
        return p[u];
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        p = vector<int> (2e4+10);
        for (int i = 0; i < p.size(); ++i) {
            p[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            Union(stones[i][0], stones[i][1] + 1e4);
        }
        unordered_set<int> vis;
        for (int i = 0; i < n; ++i) {
            vis.insert(Find(stones[i][0]));
        }
        return n - vis.size();
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> arr = {
        {0, 0},
        {1, 0},
        {1, 1}
    };
    int res = sol.removeStones(arr);
    cout << res << endl;
    return 0;
}
