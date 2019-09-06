//
//  main.cpp
//  377. Combination Sum IV
//
//  Created by 边俊林 on 2019/9/6.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/combination-sum-iv/
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
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        auto endit = upper_bound(nums.begin(), nums.end(), target);
        if (endit != nums.end())
            nums.erase(endit, nums.end());

        int n = nums.size();
        if (n <= 0) return 0;
        vector<unsigned long long> dp (target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < n && nums[j] <= i; ++j) {
                dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1,2,3
        3, 33, 333
    };
    int target = 10000;
    int res = sol.combinationSum4(nums, target);
    cout << res << endl;
    return 0;
}
