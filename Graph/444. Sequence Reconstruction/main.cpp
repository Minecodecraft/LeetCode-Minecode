//
//  main.cpp
//  444. Sequence Reconstruction
//
//  Created by 边俊林 on 2019/12/13.
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
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        color = vector<int> (n+1, 0);
        g = vector<unordered_set<int>> (n+1);
        unordered_set<int> vis;

        for (auto& seq: seqs) {
            for (int i = 0; i < (int)seq.size(); ++i) {
                if (seq[i] <= 0 || seq[i] > n) return false;
                vis.insert(seq[i]);
                if (i+1 < seq.size()) {
                    if (seq[i] == seq[i+1]) return false;
                    g[seq[i]].insert(seq[i+1]);
                }
            }
        }

        if (n == 1) return vis.size() == 1;

        vector<int> path;
        for (int i = 1; i <= n; ++i) {
            if (vis.count(i) && !dfs(i, path)) return false;
        }
        if (path.size() != n) return false;
        for (int i = 0; i < (int)path.size() - 1; ++i)
            if (g[path[i+1]].count(path[i]) == 0) return false;
        return true;
    }

private:
    vector<int> color;
    vector<unordered_set<int>> g;

    bool dfs(int u, vector<int>& path) {
        if (color[u] != 0)
            return color[u] == 2;
        color[u] = 1;
        for (auto it = g[u].begin(); it != g[u].end(); ++it) {
            if (!dfs(*it, path)) return false;
        }
        color[u] = 2;
        path.push_back(u);
        return true;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> org = {
//        1,2,3
        1
    };
    vector<vector<int>> seqs = {
//        {1,2},{1,3}
        {1}, {1}
    };
    bool res = sol.sequenceReconstruction(org, seqs);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
