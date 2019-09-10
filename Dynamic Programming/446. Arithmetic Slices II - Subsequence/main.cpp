//
//  main.cpp
//  446. Arithmetic Slices II - Subsequence
//
//  Created by 边俊林 on 2019/9/10.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
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
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        vector<unordered_map<int, int>> dp (n);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if ((long)A[i] - (long)A[j] > INT_MAX || (long)A[i] - (long)A[j] < INT_MIN) continue;
                int diff = A[i] - A[j];
                dp[i][diff] += 1;
                if (dp[j].count(diff) > 0) {
                    dp[i][diff] += dp[j][diff];
                    res += dp[j][diff];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        2, 4, 6, 8, 10
//        0,2000000000,-294967296
//        2, 2, 3, 4
//        2, 2, 3, 3, 4
//        1, 1, 1, 1
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
    };
    int res = sol.numberOfArithmeticSlices(nums);
    cout << res << endl;
    return 0;
}
