//
//  main.cpp
//  523. Continuous Subarray Sum
//
//  Created by 边俊林 on 2019/9/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/continuous-subarray-sum/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
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
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        // number of nums is less than 2
        if (len <= 1) return false;
        // at least two continuously zero
        for (int i = 0; i < len-1; ++i)
            if (nums[i] == 0 && nums[i+1] == 0) return true;
        // at this point, k can't be 0 any longer
        if (k == 0) return false;
        if (k < 0) k = -k;

        unordered_map<int, int> hashSum;
        hashSum[0] = -1;
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            for (int j = (sum / k) * k; j >= k; j -= k) {
                if (hashSum.count(sum-j) && (i-hashSum[sum-j] > 1))
                    return true;
            }
            if (hashSum.count(sum) == 0)
                hashSum[sum] = i;
        }
        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        0,1,0
//        0, 0
//        23,6,9
//        0, 0
//        1, 1
        2, 2
    };
    int k = -1;
//    int k = 6;
//    int k = 0;
    bool res = sol.checkSubarraySum(nums, k);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
