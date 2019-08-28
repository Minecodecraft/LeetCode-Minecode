//
//  main.cpp
//  309. Best Time to Buy and Sell Stock with Cooldown
//
//  Created by 边俊林 on 2019/8/28.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
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
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        int maxx = 0;
        vector<int> buy (len, 0); // buy[i] means the max profit after buy i
        vector<int> sell (len, 0); // sell[i] means the max profit after sell i
        buy[0] = -prices[0];

        for (int i = 1; i < len; ++i) {
            sell[i] = max(buy[i-1] + prices[i], sell[i-1] - prices[i-1] + prices[i]);
            maxx = max(maxx, sell[i]);

            if (i <= 1)
                buy[i] = buy[i-1] + prices[i-1] - prices[i];
            else
                buy[i] = max(sell[i-2] - prices[i], buy[i-1] + prices[i-1] - prices[i]);
        }

        return maxx;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> prices = {1,2,3,0,2};
    auto res = sol.maxProfit(prices);
    cout << res << endl;
    return 0;
}
