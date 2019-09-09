//
//  main.cpp
//  416. Partition Equal Subset Sum
//
//  Created by 边俊林 on 2019/9/9.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
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
// Solution 1: DFS
/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return !(sum & 1) && backtrack(nums, 0, sum >> 1);
    }

private:
    unordered_set<string> vis;
    bool backtrack(vector<int>& nums, int idx, int last) {
        if (last <= 0) return last == 0;
        string key = to_string(idx) + '-' + to_string(last);
        if (vis.count(key) > 0) return false;
        for (int i = idx; i < nums.size(); ++i)
            if (backtrack(nums, i+1, last-nums[i])) return true;
        vis.insert(key);
        return false;
    }
};
 */

// Solution 2: DP
/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        sum >>= 1;
        vector<bool> dp (sum+1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = sum; j >= nums[i]; --j)
                dp[j] = dp[j] | dp[j-nums[i]];
        }
        return dp[sum];
    }
};
 */

// Solution 3: Bitset
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10010> bt(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        for (int i = 0; i < nums.size(); ++i)
            bt |= bt << nums[i];
        return bt[sum >> 1];
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1, 5, 11, 5
//        1, 2, 3, 5
//        1,1
        100, 100, 100, 100, 100, 100, 100, 100, 100
//    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,97,95,99,99
    };
    bool res = sol.canPartition(nums);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
