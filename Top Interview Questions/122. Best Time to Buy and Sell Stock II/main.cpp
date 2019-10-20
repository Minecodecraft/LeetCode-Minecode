//
//  main.cpp
//  122. Best Time to Buy and Sell Stock II
//
//  Created by 边俊林 on 2019/10/20.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <utility>
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
        if (prices.size() == 0) return 0;
        int sum = 0;
        for (int i = 1; i < prices.size(); ++i) {
            sum += max(prices[i]-prices[i-1], 0);
        }
        return sum;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        7,1,5,3,6,4
    };
    int res = sol.maxProfit(nums);
    cout << res << endl;
    return 0;
}
