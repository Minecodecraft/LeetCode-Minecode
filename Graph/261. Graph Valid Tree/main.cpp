//
//  main.cpp
//  261. Graph Valid Tree
//
//  Created by 边俊林 on 2019/12/12.
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
    bool validTree(int n, vector<vector<int>>& edges) {
        g = vector<vector<int>> (n);
        color = vector<int> (n, 0);
        pre = vector<int> (n, -1);

        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        // circle
        for (int i = 0; i < n; ++i)
            if (color[i] == 0 && dfs(i) == false)
                return false;
        // count group
        vector<int> fa (n);
        for (int i = 0; i < n; ++i) fa[i] = i;
        int capa = n;
        for (auto& e: edges) {
            int pu = Find(fa, e[0]), pv = Find(fa, e[1]);
            if (pu != pv) {
                fa[pu] = pv;
                --capa;
            }
        }

        return capa == 1;
    }

private:
    vector<vector<int>> g;
    vector<int> color;
    vector<int> pre;

    bool dfs(int u) {
        color[u] = 1;
        for (auto it = g[u].begin(); it != g[u].end(); ++it) {
            int v = *it;
            if (color[v] == 1 && pre[u] != v) {
                    return false;
            } else if (color[v] == 0) {
                pre[v] = u;
                dfs(v);
            }
        }
        color[u] = 2;
        return true;
    }

    int Find(vector<int>& fa, int u) {
        if (fa[u] == u) return u;
        return fa[u] = Find(fa, fa[u]);
    }
};

int main() {
    Solution sol = Solution();
    int n = 5;
    vector<vector<int>> es = {
        {0,1},{0,2},{0,3},{1,4}
//        {0,1},{1,2},{2,3},{1,3},{1,4}
    };
    bool res = sol.validTree(n, es);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
