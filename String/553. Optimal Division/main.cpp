//
//  main.cpp
//  553. Optimal Division
//
//  Created by 边俊林 on 2019/8/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/optimal-division/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
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
    string optimalDivision(vector<int>& nums) {
        auto n = nums.size();
        if (n == 1)
            return to_string(nums[0]);
        if (n == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);

        string res = to_string(nums[0]) + "/" + "(";
        for (int i = 1; i < n; ++i) {
            if (i > 1) res += "/";
            res += to_string(nums[i]);
        }
        res += ")";
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1000, 100, 10, 2};
    string res = sol.optimalDivision(nums);
    cout << res << endl;
    return 0;
}
