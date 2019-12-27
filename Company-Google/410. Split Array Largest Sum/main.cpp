//
//  main.cpp
//  410. Split Array Largest Sum
//
//  Created by 边俊林 on 2019/12/24.
//  Copyright © 2019 边俊林. All rights reserved.
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
    int splitArray(vector<int>& nums, int m) {
        if (nums.size() == 0) return 0;
        long l = *max_element(nums.begin(), nums.end());
        long r = accumulate(nums.begin(), nums.end(), (long long)0);
        while (l < r) {
            long mid = l + (r - l) / 2;
            if (!partition(nums, mid, m-1)) l = mid+1;
            else r = mid;
        }
        return l;
    }

private:
    bool partition(vector<int>& nums, int maxval, int m) {
        long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum > maxval) {
                if (m <= 0)
                    return false;
                m--;
                sum = nums[i];
            }
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {
//        7,2,5,10,8
        1, INT_MAX
    };
    int m = 2;
    int res = sol.splitArray(arr, m);
    cout << res << endl;
    return 0;
}
