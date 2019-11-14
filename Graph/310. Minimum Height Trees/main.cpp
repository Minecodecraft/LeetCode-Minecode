//
//  main.cpp
//  310. Minimum Height Trees
//
//  Created by 边俊林 on 2019/11/13.
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
// Solution 1: Not conciselly
/*
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<int> degree (n, 0);
        unordered_map<int, vector<int>> mp;
        for (auto& e: edges) {
            degree[e[0]]++;
            degree[e[1]]++;
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        int last = n;
        queue<int> q;

        for (int i = 0; i < n; ++i)
            if (degree[i] == 1) q.push(i);

        while (q.size() && last > 2) {
            int p = q.front(); q.pop();
            degree[p]--;
            last--;
            for (auto it = mp[p].begin(); it != mp[p].end(); ++it) {
                if (--degree[*it] == 1)
                    q.push(*it);
            }
        }

        map<int, vector<int>> cnt;
        while (q.size()) {
            int p = q.front(); q.pop();
            int num = countstep(mp, p, n);
            cnt[num].push_back(p);
        }
        return cnt.empty() ? vector<int>() : cnt.begin()->second;
    }

private:
    const long long SEED = 1e6;
    int countstep(unordered_map<int, vector<int>>& mp, int idx, int n) {
        queue<long long> q;
        vector<bool> vis (n, false);
        int maxlevel = 0;
        q.push(idx + 1 * SEED);
        while (q.size()) {
            long cp = q.front(); q.pop();
            int level = cp / SEED;
            int p = cp % SEED;
            if (vis[p]) continue;
            vis[p] = true;
            maxlevel = max(maxlevel, level);

            for (auto it = mp[p].begin(); it != mp[p].end(); ++it) {
                q.push(*it + (level+1) * SEED);
            }
        }
        return maxlevel;
    }
};
 */

// Solution 2: Conciselly code
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // corner case
        if (n == 1) return {0};

        unordered_map<int, unordered_set<int>> mp;
        for (auto& e: edges) {
            mp[e[0]].insert(e[1]);
            mp[e[1]].insert(e[0]);
        }

        vector<int> curr;
        for (int i = 0; i < n; ++i)
            if (mp[i].size() == 1)
                curr.push_back(i);

        while (true) {
            vector<int> next;
            for (auto& cur: curr) {
                for (auto& adj: mp[cur]) {
                    mp[adj].erase(cur);
                    if (mp[adj].size() == 1)
                        next.push_back(adj);
                }
            }
            if (next.empty())
                return curr;
            curr = next;
        }
    }
};

int main() {
    Solution sol = Solution();
//    int n = 4;
//    int n = 6;
    int n = 1;
    vector<vector<int>> mat = {
//        {1, 0}, {1, 2}, {1, 3}
//        [0, 3], [1, 3], [2, 3], [4, 3], [5, 4]
    };
    auto res = sol.findMinHeightTrees(n, mat);
    for_each(begin(res), end(res), [](int ele) { cout << ele << ", "; });
    cout << endl;
    return 0;
}
