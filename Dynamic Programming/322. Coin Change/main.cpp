//
//  main.cpp
//  322. Coin Change
//
//  Created by 边俊林 on 2019/9/2.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/coin-change/
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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount+1, INT_MAX);
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] > i) break;
                if (dp[i-coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {
    Solution sol = Solution();
//    vector<int> coins = {1, 2, 5};
//    int amount = 11;
    vector<int> coins = {2};
    int amount = 3;
    int res = sol.coinChange(coins, amount);
    cout << res << endl;
    return 0;
}
