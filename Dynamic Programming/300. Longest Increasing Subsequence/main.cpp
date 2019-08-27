//
//  main.cpp
//  300. Longest Increasing Subsequence
//
//  Created by 边俊林 on 2019/8/27.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/longest-increasing-subsequence/
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
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp (len+1, 1);
        if (len <= 1) return len;
        int maxx = 0;
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j < i; ++j) {
                if (nums[i-1] > nums[j-1]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
                maxx = max(maxx, dp[i]);
            }
        }
        return maxx;
    }
};

int main() {
    Solution sol = Solution();
//    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
//    vector<int> nums = {10, 9, 8, 7};
    vector<int> nums = {1};
//    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    int res = sol.lengthOfLIS(nums);
    cout << res << endl;
    return 0;
}
