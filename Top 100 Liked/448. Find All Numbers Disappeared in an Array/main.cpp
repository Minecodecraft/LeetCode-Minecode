//
//  main.cpp
//  448. Find All Numbers Disappeared in an Array
//
//  Created by 边俊林 on 2019/10/19.
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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                res.push_back(i+1);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        4,3,2,7,8,2,3,1
    };
    auto res = sol.findDisappearedNumbers(nums);
    cout << res.size() << endl;
    return 0;
}
