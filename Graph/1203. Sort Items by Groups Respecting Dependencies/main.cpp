//
//  main.cpp
//  1203. Sort Items by Groups Respecting Dependencies
//
//  Created by 边俊林 on 2019/12/11.
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
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        tot = n + 2 * m;
        color = vector<int> (tot, 0);
        g = vector<vector<int>> (tot);
        
        for (int i = 0; i < n; ++i) {
            // If has group, build the in-group
            if (group[i] != -1) {
                g[n+group[i]].push_back(i);
                g[i].push_back(n+m+group[i]);
            }
            // Connect dependencies between vertexs
            for (auto& before: beforeItems[i]) {
                int from, to;
                if (group[i] != -1 && group[i] == group[before]) {
                    from = before;
                    to = i;
                } else {
                    from = group[before] == -1 ? before : n+m+group[before];
                    to = group[i] == -1 ? i : n+group[i];
                }
                g[from].push_back(to);
            }
        }
        
        stack<int> path;
        for (int i = tot-1; i >= 0; --i)
            if (!topoSortAndCheckCircle(i, path)) return vector<int>();
        vector<int> res;
        while (path.size()) {
            if (path.top() < n)
                res.push_back(path.top());
            path.pop();
        }
        return res;
    }
    
private:
    int tot;
    vector<int> color;
    vector<vector<int>> g;
    
    bool topoSortAndCheckCircle(int idx, stack<int>& path) {
        if (color[idx] != 0) return color[idx] == 2;
        color[idx] = 1;
        for (auto it = g[idx].begin(); it != g[idx].end(); ++it) {
            int v = *it;
            if (!topoSortAndCheckCircle(v, path)) return false;
        }
        color[idx] = 2;
        path.push(idx);
        return true;
    }
};

int main() {
    Solution sol = Solution();
    int n = 8, m = 2;
    vector<int> group = {-1,-1,1,0,0,1,0,-1};
    
    return 0;
}
