//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2019/10/27.
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
// Solution 1: DFS
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> path;
        unordered_set<int> vis;
        path.push_back(start);
        vis.insert(start);
        dfs(n, path, vis, start);
        return path;
    }

private:

    bool dfs(int n, vector<int>& path, unordered_set<int>& vis, int start) {
        if (path.size() == pow(2, n)) {
            int dif = path.back() ^ start;
            return (dif & (dif - 1)) == 0;
        }

        int prev = path.back();
        for (int i = 0; i < 16; ++i) {
            int nxt = prev ^ (1 << i);
            if (nxt <= pow(2, n)-1 && !vis.count(nxt)) {
                vis.insert(nxt);
                path.push_back(nxt);
                if (dfs(n, path, vis, start))
                    return true;
                path.pop_back();
                vis.erase(nxt);
            }
        }

        return false;
    }
};

int main() {
    Solution sol = Solution();
//    int n = 2, start = 3;
//    int n = 3, start = 2;
//    int n = 4, start = 1;
    int n = 5, start = 14;
    auto res = sol.circularPermutation(n, start);

    return 0;
}
