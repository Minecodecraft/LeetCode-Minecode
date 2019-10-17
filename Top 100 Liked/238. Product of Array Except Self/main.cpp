//
//  main.cpp
//  238. Product of Array Except Self
//
//  Created by 边俊林 on 2019/10/17.
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
    vector<int> productExceptSelf(vector<int>& nums) {
        int presum = 1, sufsum = 1, n = nums.size();
        vector<int> res (n, 1);
        for (int i = 0; i < n; ++i) {
            res[i] *= presum;
            presum *= nums[i];
            res[n-i-1] *= sufsum;
            sufsum *= nums[n-i-1];
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        1,2, 3,4
    };
    vector<int> res = sol.productExceptSelf(nums);
    cout << res.size() << endl;
    return 0;
}
