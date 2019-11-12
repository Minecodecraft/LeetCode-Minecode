//
//  main.cpp
//  HDU-1068. Girls and Boys
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

struct Edge {
    int from, to;
    Edge(int f, int t) : from(f), to(t) { }
};

int n, m, tmp;
vector<Edge> edges;
vector<vector<int>> G;
vector<bool> vis;
vector<int> matching;

bool match(int u) {
    for (auto it = G[u].begin(); it != G[u].end(); ++it) {
        int v = edges[*it].to;
        if (!vis[v]) {
            vis[v] = true;
            if (matching[v] == -1 || match(matching[v])) {
                matching[u] = v;
                matching[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);

    while (scanf("%d", &n) != EOF) {
        edges.clear();
        G = vector<vector<int>> (n);
        vis = vector<bool> (n, false);
        matching = vector<int> (n, -1);

        int u, v;
        for (int i = 0; i < n; ++i) {
            scanf("%d: (%d)", &u, &tmp);
            while (tmp--) {
                scanf("%d", &v);
                edges.push_back(Edge(u, v));
                G[u].push_back(edges.size()-1);
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (matching[i] == -1) {
                fill(vis.begin(), vis.end(), false);
                if (match(i))
                    ++res;
            }
        }
        printf("%d\n", n - res);
    }

    return 0;
}
