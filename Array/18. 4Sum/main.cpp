//
//  main.cpp
//  18. 4Sum
//
//  Created by 边俊林 on 2018/6/8.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ------------------------------------------------------ *\
    https://leetcode-cn.com/problems/4sum/description/
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
// Use Two-Pointers algorithm to just the last 2 values. And traverse the first two value to make every pair of them.

/// Tips:
// Be care of push the same tuple, make sure you have checked it like "while (l < r && nums[l] == nums[l-1]) l++;"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) { return {}; }
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) { continue; }
            
            for (int j = i+1; j < nums.size() - 2; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) { continue; }
                twoSum(nums, res, i, j, target);
            }
        }
        return res;
    }
private:
    void twoSum(vector<int> &nums, vector<vector<int>> &res, int idx1, int idx2, int target) {
        int l = idx2 + 1;
        int r = (int)nums.size() - 1;
        
        while (l < r) {
            int sum = nums[idx1] + nums[idx2] + nums[l] + nums[r];
            if (sum < target) { l++; }
            else if (sum > target) { r--; }
            else {
                vector<int> tmpV = {nums[idx1], nums[idx2], nums[l], nums[r]};
                res.push_back(tmpV);
                
                l++;
                r--;
                while (l < r && nums[l] == nums[l-1]) l++;
                while (l < r && nums[r] == nums[r+1]) r--;
            }
        }
    }
};

void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}
void printVectors(vector<vector<int>> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printVector(*it);
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
    
    int arr[] = {1, 0, -1, 0, -2, 2};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    int target = 0;
    
    auto res = sol.fourSum(v, target);
    printVectors(res);
    
    return 0;
}
