//
//  main.cpp
//  785. Is Graph Bipartite?
//
//  Created by 边俊林 on 2019/11/11.
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        G = vector<vector<int>> (n);
        color = vector<int> (n, 0);

        for (int i = 0; i < n; ++i) {
            for (int& v: graph[i]) {
                edges.push_back(Edge(i, v));
            }
        }

        for (int i = 0; i < edges.size(); ++i)
            G[edges[i].from].push_back(i);

        for (int i = 0; i < n; ++i) {
            if (color[i] == 0)
                if (setColor(i) == false)
                    return false;
        }
        return true;
    }

private:
    struct Edge {
        int from;
        int to;

        Edge(int f, int t)
            : from(f), to(t) {}
    };

    vector<int> color;
    vector<Edge> edges;
    vector<vector<int>> G;

    bool setColor(int u) {
        queue<int> q;
        color[u] = 1;
        q.push(u);
        while (q.size()) {
            int p = q.front(); q.pop();
            int nxtcolor = color[p] == 1 ? 2 : 1;

            for (auto it = G[p].begin(); it != G[p].end(); ++it) {
                Edge& e = edges[*it];
                if (color[e.to] == 0) {
                    color[e.to] = nxtcolor;
                    q.push(e.to);
                } else if (color[e.to] != nxtcolor) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> g = {
        {1,2,3},
        {0,2},
        {0,1,3},
        {0,2}
    };
    bool res = sol.isBipartite(g);
    cout << res << endl;
    return 0;
}
