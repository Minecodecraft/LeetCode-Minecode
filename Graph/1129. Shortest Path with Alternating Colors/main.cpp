//
//  main.cpp
//  1129. Shortest Path with Alternating Colors
//
//  Created by 边俊林 on 2019/12/10.
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
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<bool>> vis (2, vector<bool> (n, false));
        vector<vector<vector<int>>> G (n, vector<vector<int>> (2, vector<int> ()));
        for (auto& re: red_edges)
            G[re[0]][0].push_back(re[1]);
        for (auto& be: blue_edges)
            G[be[0]][1].push_back(be[1]);

        queue<Node> q;
        q.push({0, 0, 0});
        q.push({0, 1, 0});

        vector<int> res (n, -1);
        while (q.size()) {
            int color = q.front().color;
            int u = q.front().idx;
            int cnt = q.front().cnt;
            q.pop();

            if (vis[color][u]) continue;
            vis[color][u] = true;
            res[u] = res[u] == -1 ? cnt : min(res[u], cnt);

            auto& nxtPaths = G[u][1-color];
            for (auto it = nxtPaths.begin(); it != nxtPaths.end(); ++it) {
                int v = *it;
                q.push({v, 1-color, cnt+1});
            }
        }
        return res;
    }

private:
    struct Node {
        int idx, color, cnt;
    };
};

int main() {

    Solution sol = Solution();
    int n = 5;
    vector<vector<int>> re = {
        {2,2},{0,1},{0,3},{0,0},{0,4},{2,1},{2,0},{1,4},{3,4}
    };
    vector<vector<int>> be = {
        {1,3},{0,0},{0,3},{4,2},{1,0}
    };
    vector<int> res = sol.shortestAlternatingPaths(n, re, be);


    return 0;
}
