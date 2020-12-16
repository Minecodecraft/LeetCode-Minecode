//
//  main.cpp
//  1066. Campus Bikes II
//
//  Created by Jaylen Bian on 12/16/20.
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
//
class Solution {
public:
    int assignBikes(vector<vector<int>>& ws, vector<vector<int>>& bs) {
        int n = ws.size(), m = bs.size();
        auto dis = [ws, bs] (int i, int j) {
            return abs(ws[i][0] - bs[j][0]) + abs(ws[i][1] - bs[j][1]);
        };
        // dp[i][j] means the min distances when the i-th worker get a bike with the status of j
        vector<vector<int>> dp = vector<vector<int>> (n, vector<int> (1 << m, INT_MAX >> 1));
        for (int i = 0; i < m; ++i)
            dp[0][1 << i] = dis(0, i);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < (1 << m); ++k) {
                    if ((k >> j) & 1)
                        continue;
                    int mask = k + (1 << j);
                    dp[i][mask] = min(dp[i][mask], dp[i-1][k] + dis(i, j));
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < (1 << m); ++i)
            res = min(res, dp[n-1][i]);
        return res;
    }
};

int main() {

    return 0;
}
