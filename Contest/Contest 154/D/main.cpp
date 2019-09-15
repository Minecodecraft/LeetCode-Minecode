//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2019/9/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> indegree (n, 0);
        unordered_map<int, set<int>> mp;
        for (int i = 0; i < n; ++i)
            mp[i] = {};
        for (int i = 0; i < connections.size(); ++i) {
            vector<int> conn = connections[i];
            indegree[conn[0]]++;
            indegree[conn[1]]++;

            mp[conn[0]].insert(conn[1]);
            mp[conn[1]].insert(conn[0]);
        }

        queue<int> Q;
        for (int i = 0; i < n; ++i)
            if (indegree[i] == 1)
                Q.push(i);

        vector<vector<int>> res;
        while (!Q.empty()) {
            int idx = Q.front(); Q.pop();
            if (indegree[idx] != 1) continue;
            indegree[idx]--;
            auto edges = mp[idx];
            for (auto it = edges.begin(); it != edges.end(); ++it) {
                res.push_back({idx, *it});
                // clear edges
                mp[*it].erase(idx);
                indegree[*it]--;
                if (indegree[*it] == 1)
                    Q.push(*it);
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> conn = {
        {0,1}, {1,2}, {2,0}, {1,3}
    };
    auto res = sol.criticalConnections(4, conn);

    return 0;
}
