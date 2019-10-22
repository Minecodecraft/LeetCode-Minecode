//
//  main.cpp
//  162. Find Peak Element
//
//  Created by 边俊林 on 2019/10/21.
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
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            if (l + 1 == r)
                return nums[l] < nums[r] ? r : l;
            int mid = l + (r-l) / 2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            if (nums[mid] < nums[mid+1])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1, 2, 3, 1
//        1,2,1,3,5,6,4
        -2147483648
    };
    int res = sol.findPeakElement(nums);
    cout << res << endl;
    return 0;
}
