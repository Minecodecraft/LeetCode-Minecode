//
//  main.cpp
//  568. Maximum Vacation Days
//
//  Created by Jaylen Bian on 8/4/20.
//  Copyright © 2020 边俊林. All rights reserved.
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
// Solution 1: 252ms, 25MB, use memo to optimize validate flight check.
/*
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), K = days[0].size();
        vector<vector<int>> dp = vector<vector<int>> (K+1, vector<int> (n, INT_MIN));
        vector<vector<int>> fl = vector<vector<int>> (n, vector<int> ());
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i == j || flights[i][j])
                    fl[i].push_back(j);

        dp[0][0] = 0;
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k: fl[j]) {
                    dp[i+1][k] = max(dp[i+1][k], dp[i][j] + days[k][i]);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
            res = max(res, dp[K][i]);
        return res;
    }
};
 */

// Solution 2:
// 23.9MB, use scrolling array to optimize space usage.
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), K = days[0].size();
        vector<vector<int>> dp = vector<vector<int>> (2, vector<int> (n, INT_MIN));
        vector<vector<int>> fl = vector<vector<int>> (n, vector<int> ());
        int idx = 0;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i == j || flights[i][j])
                    fl[i].push_back(j);

        dp[idx][0] = 0;
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k: fl[j]) {
                    dp[1-idx][k] = max(dp[1-idx][k], dp[idx][j] + days[k][i]);
                }
            }
            idx = 1 - idx;
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
            res = max(res, dp[idx][i]);
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> fligts = {
//        {0,0,0}, {0,0,0}, {0,0,0}
        {0,1,1}, {1,0,1}, {1,1,0}
    };
    vector<vector<int>> days = {
//        {1,1,1}, {7,7,7}, {7,7,7}
        {7,0,0}, {0,7,0}, {0,0,7}
    };
    int res = sol.maxVacationDays(fligts, days);
    cout << res << endl;
    return 0;
}
