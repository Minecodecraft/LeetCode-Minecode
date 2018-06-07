//
//  main.cpp
//  16. 3Sum Closest
//
//  Created by 边俊林 on 2018/6/7.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/3sum-closest/description/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
// Use Two-Pointers algorithm to determine which result of 3-Sum-set is closest to the target.

/// Tips:
//
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        bool isFirstTimes = true;
        int res = 0;
        if (nums.size() < 2) { return -1; }
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; ++i) {
            int tmpRes = twoPointers(nums, target, i);
            if (isFirstTimes) {
                res = tmpRes;
                isFirstTimes = false;
            } else {
                res = abs(tmpRes-target) < abs(res-target) ? tmpRes : res;
            }
        }
        return res;
    }
private:
    int twoPointers(vector<int> &nums, int target, int idx) {
        int l = idx + 1, r = (int)nums.size()-1;
        bool isFirstTimes = true;
        int res = 0;
        
        while (l < r) {
            int sum = nums[idx] + nums[l] + nums[r];
            int diff = sum-target;
            if (isFirstTimes) {
                res = sum;
                isFirstTimes = false;
            } else {
                res = abs(diff) < abs(res-target) ? sum : res;
            }
            if (diff < 0) { l++; }
            else if (diff > 0) { r--; }
            else {
                return res;
            }
        }
        return res;
    }
};

void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
    
    int arr[] = {1, 1, -1, -1, 3};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    int target = -1;
    
    auto res = sol.threeSumClosest(v, target);
    printf("%d\n", res);
    
    return 0;
}
