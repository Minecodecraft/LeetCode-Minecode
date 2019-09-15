//
//  main.cpp
//  494. Target Sum
//
//  Created by 边俊林 on 2019/9/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/target-sum/
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
// Solution 1: Recursion Brute Force O(2^n)
/*
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, 0, 0, S);
    }

private:
    int dfs(vector<int>& nums, int idx, int sum, int target) {
        if (idx == nums.size()) return sum == target ? 1 : 0;

        int cnt = 0;
        cnt += dfs(nums, idx+1, sum + nums[idx], target);
        cnt += dfs(nums, idx+1, sum - nums[idx], target);
        return cnt;
    }
};
 */

// Solution 2: Recursion with memorization O(l*n), l depends on sum
/*
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> memo (nums.size(), vector<int> (2010, INT_MIN));
        return dfs(nums, 0, 0, S, memo);
    }

private:
    int dfs(vector<int>& nums, int idx, int sum, int target, vector<vector<int>>& memo) {
        if (idx == nums.size())
            return target == sum;
        if (memo[idx][sum+1000] != INT_MIN)
            return memo[idx][sum+1000];

        int cnt = dfs(nums, idx+1, sum + nums[idx], target, memo);
        cnt += dfs(nums, idx+1, sum - nums[idx], target, memo);

        return memo[idx][sum+1000] = cnt;
    }
};
 */

// Solution 3: Dynamic Programming
// Define the subset of positive number is P, and negative is M
// So we can find out the formula as follow:
// sum[P] - sum[M] = S
// sum[P] + sum[M] + sum[P] - sum[M] = S + sum[P] + sum[M];
// 2 * sum[P] = S + sum(nums)
// sum[P] = (S + sum(nums)) / 2
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long sum = accumulate(nums.begin(), nums.end(), 0);
        sum += S;
        if ((sum & 1) || (sum < 2*S))  return 0;
        return solve(nums, sum >> 1);
    }

private:
    int solve(vector<int>& nums, long sum) {
        vector<int> dp (sum+1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = sum; j >= nums[i]; --j) {
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};


int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1,1,1,1, 1
//        1,2,7,9,981
        2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53
    };
    int k = 2147483647;
//    int k = 100000000;
//    int k = 3;
    int res = sol.findTargetSumWays(nums, k);
    cout << res << endl;
    return 0;
}
