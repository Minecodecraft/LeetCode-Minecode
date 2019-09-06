//
//  main.cpp
//  375. Guess Number Higher or Lower II
//
//  Created by 边俊林 on 2019/9/5.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/guess-number-higher-or-lower-ii/
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
    int getMoneyAmount(int n) {
        vector<vector<int>> dp (n+1, vector<int> (n+1, 0));
        return getRangeAmount(dp, 1, n);
    }

private:
    int getRangeAmount(vector<vector<int>>& dp, int b, int e) {
        if (b >= e)
            return 0;
        if (dp[b][e] != 0)
            return dp[b][e];
        int res = INT_MAX;
        for (int mid = b; mid <= e; ++mid) {
            int curmin = mid + max(getRangeAmount(dp, b, mid-1),
                                   getRangeAmount(dp, mid+1, e));
            res = min(res, curmin);
        }
        dp[b][e] = res;
        return res;
    }
};

int main() {
    Solution sol = Solution();
    int n = 10;
//    int n = 5;
    int res = sol.getMoneyAmount(n);
    cout << res << endl;
    return 0;
}
