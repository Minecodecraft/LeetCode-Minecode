//
//  main.cpp
//  70. Climbing Stairs
//
//  Created by 边俊林 on 2019/8/19.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/climbing-stairs/
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
    int climbStairs(int n) {
        vector<int> dp (n+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i-1];
            if (i >= 2)
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};

int main() {
    Solution sol = Solution();
//    int n = 2;
    int n = 3;
    int res = sol.climbStairs(n);
    cout << res << endl;
    return 0;
}
