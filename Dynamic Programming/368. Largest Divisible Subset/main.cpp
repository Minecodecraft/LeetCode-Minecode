//
//  main.cpp
//  368. Largest Divisible Subset
//
//  Created by 边俊林 on 2019/9/5.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/largest-divisible-subset/
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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<vector<int>> dp (nums.size()+1, vector<int> ());
        sort(nums.begin(), nums.end());
        dp[0] = {};
        for (int i = 0; i < nums.size(); ++i)
            dp[i+1] = {nums[i]};
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j < i; ++j) {
                int ni = nums[i-1], nj = nums[j-1];
                if (nj == ni || (nj > ni && nj % ni == 0) || (ni > nj && ni % nj == 0)) {
                    vector<int> arr = dp[j];
                    if (arr.size() + 1 > dp[i].size()) {
                        arr.push_back(ni);
                        dp[i] = arr;
                    }
                }
            }
        }
        vector<int> res = {};
        for (auto &elem: dp) {
            if (elem.size() > res.size())
                res = elem;
        }
        return res;
    }
};

// Tool Function List
void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1,2,3
//        1, 2, 3, 4
        1, 2, 4, 8
    };
    auto res = sol.largestDivisibleSubset(nums);
    printVector(res);
    return 0;
}
