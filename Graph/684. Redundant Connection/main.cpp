//
//  main.cpp
//  684. Redundant Connection
//
//  Created by 边俊林 on 2019/11/25.
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
    vector<int> findRedundantConnection(vector<vector<int>>& es) {
        for (auto& edge: es)
            n = max(n, max(edge[0], edge[1]));

        G = vector<vector<int>> (n+1);
        color = vector<int> (n+1, 0);
        fa = vector<int> (n+1, -1);
        path = unordered_set<int> ();

        for (auto& edge: es) {
            int u = edge[0], v = edge[1];
            edges.push_back(Edge(u, v));
            G[u].push_back((int)edges.size()-1);
            edges.push_back(Edge(v, u));
            G[v].push_back((int)edges.size()-1);
        }

        for (int i = 1; i <= n; ++i) {
            if (path.size()) break;
            if (color[i] == 0) dfs(i);
        }

        for (auto it = es.rbegin(); it != es.rend(); ++it) {
            int u = min((*it)[0], (*it)[1]), v = max((*it)[0], (*it)[1]);
            if (path.count(u + v * 100000))
                return {u, v};
        }
        return vector<int> ();
    }

private:
    struct Edge {
        int from, to;
        Edge (int f, int t)
        : from(f), to(t) { }
    };

    vector<vector<int>> G;
    vector<Edge> edges;
    vector<int> color;
    vector<int> fa;
    unordered_set<int> path;
    int n;

    void dfs(int u) {
        color[u] = 1;
        for (auto it = G[u].begin(); it != G[u].end(); ++it) {
            if (path.size()) return;
            int v = edges[*it].to;
            if (color[v] == 1 && v != fa[u]) {
                int tmp = u, last = v;
                path.insert(min(tmp, last) + max(tmp, last) * 100000);
                while (tmp != v) {
                    last = tmp;
                    tmp = fa[tmp];
                    path.insert(min(tmp, last) + max(tmp, last) * 100000);
                }
            } else if (color[v] == 0) {
                fa[v] = u;
                dfs(v);
            }
        }
        color[u] = 2;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
//        {1, 2}, {1, 3}, {2, 3}
        {1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}
    };
    auto res = sol.findRedundantConnection(mat);
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
    return 0;
}
