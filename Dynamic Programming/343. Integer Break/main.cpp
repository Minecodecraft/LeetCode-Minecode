//
//  main.cpp
//  343. Integer Break
//
//  Created by 边俊林 on 2019/9/3.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/integer-break/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
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
    int integerBreak(int n) {
        vector<vector<int>> dp (n+1, vector<int> (n+1, INT_MIN));
        dp[0][1] = 1;
        for (int i = 1; i <= n; ++i)
            dp[i][1] = i;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= ((i+1) >> 1); ++j) {
                for (int k = 2; k <= n; ++k) {
                    if (dp[i-j][k-1] != INT_MIN)
                        dp[i][k] = max(dp[i][k], dp[i-j][k-1] * j);
                }
            }
        }
        int maxx = INT_MIN;
        for (int i = 2; i <= n; ++i) {
            maxx = max(maxx, dp[n][i]);
        }
        return maxx;
    }
};

int main() {
    Solution sol = Solution();
//    int n = 2;
    int n = 10;
    int res = sol.integerBreak(n);
    cout << res << endl;
    return 0;
}
