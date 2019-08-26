//
//  main.cpp
//  198. House Robber
//
//  Created by 边俊林 on 2019/8/26.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/house-robber/
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
        vector<int> dp (len+1, 0);
        if (len <= 0) return 0;
        dp[1] = nums[0];
        for (int i = 2; i <= len; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[len];
    }
};

int main() {
    Solution sol = Solution();
//    vector<int> nums = {1, 2, 3, 1};
    vector<int> nums = {2,7,9,3,1};
    int res = sol.rob(nums);
    cout << res << endl;
    return 0;
}
