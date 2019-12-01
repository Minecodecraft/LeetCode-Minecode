//
//  main.cpp
//  802. Find Eventual Safe States
//
//  Created by 边俊林 on 2019/12/1.
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
// Solution 1: Ugly dfs, only beats 10%
/*
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int sz = graph.size();
        G = vector<vector<int>> (sz);
        
        for (int i = 0; i < sz; ++i) {
            for (int& e: graph[i]) {
                edges.push_back(Edge(i, e));
                G[i].push_back(edges.size()-1);
            }
        }
        
        vector<int> res;
        unordered_set<int> vis;
        for (int i = 0; i < sz; ++i) {
            vis.clear();
            if (!hasCircle(i, vis)) res.push_back(i);
        }
            
        return res;
    }
    
private:
    struct Edge {
        int from, to;
        Edge(int f, int t)
            : from(f), to(t) { }
    };

    vector<vector<int>> G;
    vector<Edge> edges;
    unordered_map<int, bool> cache;
    
    bool hasCircle(int u, unordered_set<int>& vis) {
        if (cache.count(u) > 0)
            return cache[u];
        if (vis.count(u))
            return true;
        vis.insert(u);
        
        bool has = false;
        for (auto it = G[u].begin(); it != G[u].end(); ++it) {
            int v = edges[*it].to;
            has |= hasCircle(v, vis);
            if (has) break;
        }
        vis.erase(u);
        return cache[u] = has;
    }
};
 */

// Solution 2: Optimized code, beats 100%
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int sz = graph.size();
        dp = vector<int> (sz, 0);
        vector<int> res;
        for (int i = 0; i < sz; ++i)
            if (dfs(graph, i))
                res.push_back(i);
        return res;
    }
    
private:
    vector<int> dp;
    bool dfs(vector<vector<int>>& graph, int u) {
        if (dp[u] != 0)
            return dp[u] == 1;
        
        dp[u] = -1;
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i];
            if (!dfs(graph, v))
                return false;
        }
        return dp[u] = 1;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
//        {0}, {2, 3, 4}, {3, 4}, {0, 4}, {}
//        {1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}
        {2,3}, {2,3,4}, {3,4}, {}, {1}
    };
    auto res = sol.eventualSafeNodes(mat);
    for_each(res.begin(), res.end(), [](int ele) { cout << ele << ", "; });
    cout << endl;
    return 0;
}
