//
//  main.cpp
//  120. Triangle
//
//  Created by Minecode on 2019/7/11.
//  Copyright © 2019 minecode. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/triangle/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        if (len <= 0) return 0;
        vector<vector<int>> dp (len, vector<int>(len+1, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < len; ++i) {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
            for (int j = 1; j < i; ++j) {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
        int minn = INT_MAX;
        for (int i = 0; i < len; ++i) minn = min(dp[len-1][i], minn);
        return minn;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> nums = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    auto res = sol.minimumTotal(nums);
    cout << res << endl;
    return 0;
}
