//
//  main.cpp
//  121. Best Time to Buy and Sell Stock
//
//  Created by 边俊林 on 2019/8/20.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
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
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minPrice);
        }
        return maxProfit;
    }
};

int main() {
    Solution sol = Solution();
//    vector<int> prices = {7, 1, 5, 3, 6, 4};
    vector<int> prices = {7,6,4,3,1};
    int res = sol.maxProfit(prices);
    cout << res << endl;
    return 0;
}
