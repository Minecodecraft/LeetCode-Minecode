//
//  main.cpp
//  [Array]Remove Duplicates from Sorted Array
//
//  Created by 边俊林 on 2019/7/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/
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
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int p = 0, maxx = nums[0]-1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > maxx) {
                maxx = nums[i];
                nums[p++] = maxx;
            }
        }
        return p;
    }
};


int main() {
    Solution sol = Solution();
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    auto res = sol.removeDuplicates(nums);
    cout << res << endl;
    return 0;
}
