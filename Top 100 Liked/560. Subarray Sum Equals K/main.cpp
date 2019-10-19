//
//  main.cpp
//  560. Subarray Sum Equals K
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
// Solution 1: Presum array, time beats only 5%
/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum (n+1, 0);
        for (int i = 0; i < n; ++i)
            sum[i+1] = sum[i] + nums[i];
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int diff = sum[j+1] - sum[i];
                if (diff == k) ++res;
            }
        }
        return res;
    }
};
 */

// Solution 2: Prefix sum with map
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> tot = {{0, 1}};
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res += tot[sum - k];
            tot[sum]++;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        1,1,1
    };
    int k = 2;
    int res = sol.subarraySum(nums, k);
    cout << res << endl;
    return 0;
}
