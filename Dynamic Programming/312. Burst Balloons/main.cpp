//
//  main.cpp
//  312. Burst Balloons
//
//  Created by 边俊林 on 2019/8/29.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/burst-balloons/
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
    int maxCoins(vector<int>& nums) {
        vector<int> arr (nums.begin(), nums.end());
        arr.insert(arr.begin(), 1);
        arr.insert(arr.end(), 1);
        int len = arr.size();
        // dp[i][j] means the maximum coins get after burst all the balloons in [i..j]
        vector<vector<int>> dp (len, vector<int> (len, 0));

        for (int rangelen = 1; rangelen <= len-2; ++rangelen) {
            for (int left = 0; left < len-rangelen-1; ++left) { // left [0, len-2]
                int right = left + rangelen + 1;
                for (int idx = left+1; idx < right; ++idx) {
                    dp[left][right] = max(dp[left][right], arr[left]*arr[idx]*arr[right] + dp[left][idx] + dp[idx][right]);
                }
            }
        }

        return dp[0][len-1];
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {3, 1, 5, 8};
    int res = sol.maxCoins(nums);
    cout << res << endl;
    return 0;
}
