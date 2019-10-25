//
//  main.cpp
//  210. Course Schedule II
//
//  Created by 边俊林 on 2019/10/24.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> adjs;
        unordered_map<int, unordered_set<int>> reqs;
        for (int i = 0; i < prerequisites.size(); ++i) {
            auto req = prerequisites[i];
            reqs[req[0]].insert(req[1]);
            adjs[req[1]].insert(req[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (reqs[i].empty())
                q.push(i);
        }
        int tot = 0;
        vector<bool> vis (numCourses, false);
        vector<int> path;
        while (q.size()) {
            int cur = q.front(); q.pop();
            path.push_back(cur);
            tot++;
            auto curadjs = adjs[cur];
            for (auto& adj: curadjs) {
                reqs[adj].erase(cur);
                if (reqs[adj].empty() && !vis[adj]) {
                    q.push(adj);
                    vis[adj] = true;
                }
            }
        }
        if (tot == numCourses)
            return path;
        return {};
    }
};

int main() {
    Solution sol = Solution();
//    int n = 2;
    int n = 4;
    vector<vector<int>> pres = {
//        {1, 0}
        {1, 0}, {2, 0}, {3, 1}, {3, 2}
    };
    auto res = sol.findOrder(n, pres);
    cout << res.size() << endl;
    return 0;
}
