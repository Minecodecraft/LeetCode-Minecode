//
//  main.cpp
//  334. Increasing Triplet Subsequence
//
//  Created by 边俊林 on 2019/10/31.
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
// Solution 1: Best solution 😁
/*
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (a >= nums[i]) a = nums[i];  // must have `equal`
            else if (b >= nums[i]) b = nums[i]; // must have `equal`
            else return true;
        }
        return false;
    }
};
 */

// Solution 2: Not an available solution, but it's still claver
// The problem ask me to solve in O(1) space complexity, but in fact this is O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        vector<int> pre(nums.size(), nums.front()), nxt(nums.size(), nums.back());
        for (int i = 1; i < nums.size(); ++i)
            pre[i] = min(pre[i-1], nums[i]);
        for (int i = nums.size()-2; i >= 0; --i)
            nxt[i] = max(nxt[i+1], nums[i]);
        for (int i = 1; i < nums.size()-1; ++i)
            if (nums[i] > pre[i] && nums[i] < nxt[i])
                return true;
        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1, 2, 3, 4, 5
        5, 4, 3, 2, 1
//        1, 2, 1, 4 ,5
//        5,1,5,5,2,5,4
    };
    bool res = sol.increasingTriplet(nums);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
