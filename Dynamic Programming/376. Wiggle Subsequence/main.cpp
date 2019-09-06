//
//  main.cpp
//  376. Wiggle Subsequence
//
//  Created by 边俊林 on 2019/9/6.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/wiggle-subsequence/
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
// Solution 1    O(n^2) solution
/*
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return 0;
        if (n == 1) return 1;
        vector<vector<int>> dp (n, vector<int> (2, 1));
        int downidx = 0, upidx = 0;
        // dp[i][0] means dp[i] comes from a smaller one
        int maxx = INT_MIN;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] < nums[j])
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                else if (nums[i] > nums[j])
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                maxx = max(maxx, max(dp[i][0], dp[i][1]));
            }
        }
        return maxx;
    }
};
 */

// Solution 2   O(n) solution
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return 0;
        int up = 1, down = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1])
                up = down+1;
            else if (nums[i-1] > nums[i])
                down = up+1;
        }
        return max(up, down);
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1,7,4,9,2,5
//        1,17,5,10,13,15,10,5,16,8
        1,2,3,4,5,6,7,8,9
    };
    int res = sol.wiggleMaxLength(nums);
    cout << res << endl;
    return 0;
}
