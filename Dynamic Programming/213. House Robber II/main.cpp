//
//  main.cpp
//  213. House Robber II
//
//  Created by 边俊林 on 2019/8/26.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/house-robber-ii/
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
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return 0;
        vector<vector<int>> dp (2, vector<int>(len+1, 0));
        for (int kase = 0; kase < 2; ++kase) {
            dp[kase][1] = kase == 0 ? nums[0] : 0;
            for (int i = 2; i <= len; ++i) {
                dp[kase][i] = max(dp[kase][i-1], dp[kase][i-2] + nums[i-1]);
                if (kase == 0 && i == len)
                    dp[kase][i] = dp[kase][i-1];
            }
        }
        return max(dp[0][len], dp[1][len]);
    }
};

int main() {
    Solution sol = Solution();
//    vector<int> nums = {2,3,2};
//    vector<int> nums = {1, 2, 3, 1};
    vector<int> nums = {1};
    int res = sol.rob(nums);
    cout << res << endl;
    return 0;
}
