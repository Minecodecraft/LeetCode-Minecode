//
//  main.cpp
//  188. Best Time to Buy and Sell Stock IV
//
//  Created by 边俊林 on 2019/8/25.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
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
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len <= 1 || k == 0) return 0;
        if (k > len/2) {
            int res = 0;
            for (int i = 1; i < len; ++i) {
                if (prices[i] > prices[i-1])
                    res += prices[i]-prices[i-1];
            }
            return res;
        }
        // dp[i][j] means the max profit util stock i for k transactions
        vector<vector<int>> dp (k+1, vector<int> (len+1, 0));
        int maxProfit = INT_MIN;
        for (int i = 1; i <= k; ++i) {
            int maxValueAfterBuy = dp[i-1][0] - prices[0];
            for (int j = 1; j < len; ++j) {
                dp[i][j] = max(dp[i][j-1], maxValueAfterBuy+prices[j]);
                maxValueAfterBuy = max(maxValueAfterBuy, dp[i-1][j]-prices[j]);
                maxProfit = max(maxProfit, dp[i][j]);
            }
        }
        return maxProfit;
    }
};


int main() {
    Solution sol = Solution();
    int k = 2;
//    vector<int> prices = {2, 4, 1};
    vector<int> prices = {3,2,6,5,0,3};
    auto res = sol.maxProfit(k, prices);
    cout << res << endl;
    return 0;
}
