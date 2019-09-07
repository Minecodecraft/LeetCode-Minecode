//
//  main.cpp
//  410. Split Array Largest Sum
//
//  Created by 边俊林 on 2019/9/7.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/split-array-largest-sum/
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
// Solution 1: O(nlogn)
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long l = 0, r = 0;
        for (int i = 0; i < nums.size(); ++i) {
            l = max(l, (long long)nums[i]);
            r += nums[i];
        }
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (splitWorkable(nums, m-1, mid)) r = mid;
            else l = mid + 1;
        }
        return (int) l;
    }

private:
    bool splitWorkable(vector<int>& nums, int m, long long maxval) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > maxval)
                return false;
            if (sum + nums[i] <= maxval)
                sum += nums[i];
            else {
                sum = nums[i];
                if (--m < 0) return false;
            }
        }
        return true;
    }
};

// Solution 2: O(n^3)  🤢Too bad
/*
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long> sum (n+1, 0);
        for (int i = 0; i < n; ++i)
            sum[i+1] = sum[i] + nums[i];

        vector<vector<long>> dp (n+1, vector<long> (m+1, LONG_MAX));
        for (int i = 0; i <= m; ++i)
            dp[0][i] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int k = 1; k <= min(i, m); ++k) {
                    dp[i][k] = min(dp[i][k], max(dp[j][k-1], (sum[i]-sum[j]) ));
                }
            }
        }
        return dp[n][m];
    }
};
 */

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        7,2,5,10,8
//        1, 2147483647
    };
    int m = 2;
    int res = sol.splitArray(nums, m);
    cout << res << endl;
    return 0;
}
