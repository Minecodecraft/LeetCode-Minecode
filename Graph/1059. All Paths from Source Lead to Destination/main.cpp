//
//  main.cpp
//  1059. All Paths from Source Lead to Destination
//
//  Created by 边俊林 on 2019/12/7.
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
    bool leadsToDestination(int n, vector<vector<int>>& edges, int src, int des) {
        G = vector<vector<int>> (n);
        for (int i = 0; i < edges.size(); ++i)
            G[edges[i][0]].push_back(i);

        if (G[des].size()) return false;

        unordered_set<int> vis;
        return backtracking(vis, edges, src, des);
    }

private:
    vector<vector<int>> G;


    bool backtracking(unordered_set<int>& vis, vector<vector<int>>& edges, int idx, int des) {
        if (vis.count(idx) && idx != des) return false;
        vis.insert(idx);

        if (idx == des) return true;
        if (idx != des && G[idx].empty())
            return false;

        for (auto it = G[idx].begin(); it != G[idx].end(); ++it) {
            int nxt = edges[*it][1];
            if (!backtracking(vis, edges, nxt, des)) return false;
        }
        vis.erase(idx);
        return true;
    }
};

int main() {
    Solution sol = Solution();
//    int n = 3;
    int n = 4;
    vector<vector<int>> e = {
//        {0, 1}, {0, 2}
        {0,1},{0,2},{1,3},{2,3}
    };
//    int src = 0, des = 2;
    int src = 0, des = 3;
    bool res = sol.leadsToDestination(n, e, src, des);
    cout << res << endl;
    return 0;
}
