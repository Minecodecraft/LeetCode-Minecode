//
//  main.cpp
//  152. Maximum Product Subarray
//
//  Created by 边俊林 on 2019/8/22.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/maximum-product-subarray/
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
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int posmax, negmax, maxx;
        posmax = negmax = 0;
        maxx = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0)
                swap(posmax, negmax);
            posmax = max(nums[i], posmax * nums[i]);
            negmax = min(nums[i], negmax * nums[i]);
            maxx = max(maxx, posmax);
        }
        return maxx;
    }
};

int main() {
    Solution sol = Solution();
//    vector<int> nums = {2, 3, -2, 4};
//    vector<int> nums = {1,0,-1,2,3,-5,-2};
//    vector<int> nums = {-2, 0, -1};
    vector<int> nums = {-2};
//    vector<int> nums = {0, 2};
    int res = sol.maxProduct(nums);
    cout << res << endl;
    return 0;
}
