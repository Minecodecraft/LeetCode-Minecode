//
//  main.cpp
//  581. Shortest Unsorted Continuous Subarray
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
// Solution 1: O(nlogn) with sort
/*
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sarr (nums);
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = n - 1;
        while (l < n && nums[l] == sarr[l])
            l++;
        while (r > l && nums[r] == sarr[r])
            r--;
        return r - l + 1;
    }
};
 */

// Solution 2: O(n)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> minl (n), maxr (n);
        for (int i = n - 1, prev_min = INT_MAX; i >= 0; --i)
            minl[i] = prev_min = min(prev_min, nums[i]);

        for (int i = 0, nxt_max = INT_MIN; i < n; ++i)
            maxr[i] = nxt_max = max(nxt_max, nums[i]);

        int l = 0, r = n-1;
        while (l < n && nums[l] <= minl[l]) ++l;
        while (r > l && nums[r] >= maxr[r]) --r;
        return r - l + 1;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        2, 6, 4, 8, 10, 9, 15
//        1, 2, 3, 5, 4
        1, 3, 2, 2, 2
    };
    int res = sol.findUnsortedSubarray(nums);
    cout << res << endl;
    return 0;
}
