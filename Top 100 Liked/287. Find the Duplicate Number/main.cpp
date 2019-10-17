//
//  main.cpp
//  287. Find the Duplicate Number
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
// Solution 1: Too slow, beat 5%
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                if (nums[i] == nums[j]) return nums[i];
            }
        }
        return res;
    }
};
 */

// Solution 2: Use two pointer
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1, 3, 4, 2, 2
        3,1,3,4,2
    };
    int res = sol.findDuplicate(nums);
    cout << res << endl;
    return 0;
}
