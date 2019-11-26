//
//  main.cpp
//  685. Redundant Connection II
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        fa = vector<int>(edges.size()+1, 0);
        for (int i = 0; i <= edges.size(); ++i) fa[i] = i;
        vector<int> prev (edges.size()+1, 0);

        vector<int> curEdge, preEdge, circle;
        for (auto& e: edges) {
            int u = e[0], v = e[1];
            if (prev[v] != 0) {
                // indegree >= 2
                curEdge = e;
                //
                preEdge = {prev[v], v};
            } else {
                prev[v] = u;
                if (!Union(u, v))
                    circle = {u, v};
            }
        }
        if (curEdge.size() && preEdge.size()) {
            if (circle.size()) // 如果发现了环，那么一定是首先加入的是环中的边
                return preEdge;
            // 如果没发现环，要么是先加入了非环中的边，要么是整个图并没有环
            return curEdge;
        }
        return circle;
    }

private:
    vector<int> fa;
    bool Union(int u, int v) {
        int fu = find(u);
        int fv = find(v);
        if (fu == fv) return false;
        fa[fu] = fv;
        return true;
    }

    int find(int u) {
        if (fa[u] == u) return u;
        return fa[u] = find(fa[u]);
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
//        {1, 2}, {1, 3}, {2, 3}
//        {1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}
        {2,1},{3,1},{4,2},{1,4}
    };
    auto res = sol.findRedundantDirectedConnection(mat);
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
    return 0;
}
