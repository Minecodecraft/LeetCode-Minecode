//
//  main.cpp
//  886. Possible Bipartition
//
//  Created by 边俊林 on 2019/11/12.
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        color = vector<int> (n+1, 0);
        G = vector<vector<int>> (n+1);
        sz = n;
        for (auto& dislk: dislikes) {
            edges.push_back(Edge(dislk[0], dislk[1]));
            G[dislk[0]].push_back(edges.size()-1);
            edges.push_back(Edge(dislk[1], dislk[0]));
            G[dislk[1]].push_back(edges.size()-1);
        }
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0)
                if (check(i) == false)
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
    int sz = 0;

    bool check(int u) {
        queue<int> q;
        color[u] = 1;
        q.push(u);
        while (q.size()) {
            int p = q.front(); q.pop();
            int nxtcolor = color[p] == 1 ? 2 : 1;

            for (auto it = G[p].begin(); it != G[p].end(); ++it) {
                auto& e = edges[*it];
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
    vector<vector<int>> dis = {
//        {1,2}, {1,3}, {2,3}
        {1,2},{1,3},{1,4},{1,5}
    };
//    int n = 3;
    int n = 5;
    bool res = sol.possibleBipartition(n, dis);
    cout << (res ? "true" : "false" ) << endl;
    return 0;
}
