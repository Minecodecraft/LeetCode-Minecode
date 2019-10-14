//
//  main.cpp
//  818. Race Car
//
//  Created by 边俊林 on 2019/10/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/race-car/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>tan
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
// Solution 1: BFS Solution with purning, beat 33%
/*
class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> q;
        unordered_set<pair<int, int>, set_hash> vis;
        q.emplace(0, 1);
        vis.insert(q.front());
        for (int step = 0; ; ++step) {
            for (int cnt = q.size(); cnt; cnt--) {
                pair<int, int> cur = q.front(); q.pop();

                if (cur.first == target) return step;

                auto nxtPir = make_pair(cur.first+cur.second, cur.second*2);
                if (!vis.count(nxtPir) && abs(nxtPir.first - target) < target) {
                    q.emplace(nxtPir);
                    vis.emplace(nxtPir);
                }

                auto reversePir = make_pair(cur.first, cur.second>0 ? -1 : 1);
                if (!vis.count(reversePir)) {
                    q.emplace(reversePir);
                    vis.emplace(reversePir);
                }
            }
        }
        return 0;
    }

private:
    struct set_hash {
        size_t operator() (const pair<int, int>& elem) const {
            return size_t(elem.first) * size_t(1e5+10) + elem.second;
        }
    };
};
 */

// Solution 2: DP
class Solution {
public:
    int racecar(int target) {
        maxbit = floor(log2(target)) + 1;
        dp = vector<int> (min((int)1e4+10, 1 << maxbit), 0);
        return recur(target);
    }

private:
    int maxbit;
    vector<int> dp;

    int recur(int target) {
        if (dp[target] > 0) return dp[target];

        int bitcnt = floor(log2(target)) + 1;
        if (target == (1 << bitcnt) - 1)
            dp[target] = bitcnt;
        else {
            dp[target] = recur((1 << bitcnt) - 1 - target) + bitcnt + 1;
            for (int i = 0; i < bitcnt-1; ++i) {
                int subtarget = target - (1 << (bitcnt-1)) + (1 << i);
                dp[target] = min(dp[target], recur(subtarget) + bitcnt + i + 1);
            }
        }
        return dp[target];
    }
};

int main() {
    Solution sol = Solution();
//    int n = 3;
//    int n = 6;
    int n = 30;
    int res = sol.racecar(n);
    cout << res << endl;
    return 0;
}
