//
//  main.cpp
//  123. Best Time to Buy and Sell Stock III
//
//  Created by 边俊林 on 2019/8/20.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
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
// Solution 1:
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1st, sell1st, buy2nd, sell2nd;
        buy1st = buy2nd = INT_MAX;
        sell1st = sell2nd = 0;
        for (int i = 0; i < prices.size(); ++i) {
            buy1st = min(buy1st, prices[i]);
            sell1st = max(sell1st, prices[i]-buy1st);
            buy2nd = min(buy2nd, prices[i]-sell1st);
            sell2nd = max(sell2nd, prices[i]-buy2nd);
        }
        return sell2nd;
    }
};
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int k = 2;
        // dp[i][j] means the max profit until price[j] (without sold price[j] if buy it) for at most k transactions
        vector<vector<int>> dp = vector<vector<int>> (k+1, vector<int> (prices.size()+1, 0));
        int maxProfit = INT_MIN;
        for (int i = 1; i <= k; ++i) {
            int maxValAfterBuy = dp[i-1][0] - prices[0];
            for (int j = 1; j < prices.size(); ++j) {
                dp[i][j] = max(dp[i][j-1], prices[j]+maxValAfterBuy);
                maxValAfterBuy = max(maxValAfterBuy, dp[i-1][j] - prices[j]);
                maxProfit = max(maxProfit, dp[i][j]);
            }
        }
        return maxProfit;
    }
};

int main() {
    Solution sol = Solution();
//    vector<int> nums = {3,3,5,0,0,3,1,4};
//    vector<int> nums = {1,2,3,4,5};
//    vector<int> nums = {7,6,4,3,1};
    vector<int> nums = {0};
    int res = sol.maxProfit(nums);
    cout << res << endl;
    return 0;
}
