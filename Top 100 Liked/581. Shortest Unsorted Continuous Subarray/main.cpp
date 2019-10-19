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
