//
//  main.cpp
//  283. Move Zeroes
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
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0, idx = 0;
        while (r < nums.size()) {
            while (r < nums.size() && nums[r] == 0) ++r;
            if (r < nums.size()) nums[idx++] = nums[r++];
        }
        for (; idx < nums.size(); ++idx)
            nums[idx] = 0;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        0,1,0,3,12
        0
    };
    sol.moveZeroes(nums);
    for_each(nums.begin(), nums.end(), [](int& elem) { cout << elem << ", "; });
    return 0;
}
