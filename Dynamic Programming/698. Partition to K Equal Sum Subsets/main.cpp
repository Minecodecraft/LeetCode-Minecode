//
//  main.cpp
//  698. Partition to K Equal Sum Subsets
//
//  Created by 边俊林 on 2019/9/10.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
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
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if ((sum % k) & 1) return false;
        if (k <= 1) return true;
        vector<bool> vis (nums.size(), false);
        return backtrack(nums, vis, k-1, 0, 0, sum / k);
    }

private:
    bool backtrack(vector<int>& nums, vector<bool>& vis, int last, int startIdx, int cursum, int target) {
        if (last == 0) return true;
        if (cursum == target) return backtrack(nums, vis, last-1, 0, 0, target);
        for (int i = startIdx; i < nums.size(); ++i) {
            if (vis[i]) continue;
            vis[i] = true;
            if (backtrack(nums, vis, last, i+1, cursum+nums[i], target))
                return true;
            vis[i] = false;
        }
        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        4, 3, 2, 3, 5, 2, 1
//        4, 3, 2, 3, 5, 2
//        5,2,5,5,5,5,5,5,5,5,5,5,5,5,5,3
        960,3787,1951,5450,4813,752,1397,801,1990,1095,3643,8133,893,5306,8341,5246
    };
    bool res = sol.canPartitionKSubsets(nums, 6);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
