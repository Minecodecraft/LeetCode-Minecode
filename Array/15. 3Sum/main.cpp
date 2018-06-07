//
//  main.cpp
//  15. 3Sum
//
//  Created by 边俊林 on 2018/6/7.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ------------------------------------------------------ *\
    https://leetcode-cn.com/problems/3sum/description/
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
//

/// Tips:
//

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        if (nums.size() < 3) { return res; }
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0  && nums[i] == nums[i-1]) { continue; }
            twoSum(res, nums, i);
        }
        
        return res;
    }
private:
    void twoSum(vector<vector<int>> &res, vector<int> &nums, int idx) {
        int l = idx+1;
        int r = (int)nums.size()-1;
        
        while(l <  r) {
            int sum = nums[idx]+nums[l]+nums[r];
            if (sum < 0) { l++; }
            else if (sum > 0) { r--; }
            else {
                vector<int> tmpV;
                tmpV.push_back(nums[idx]);
                tmpV.push_back(nums[l]);
                tmpV.push_back(nums[r]);
                res.push_back(tmpV);
                
                ++l;
                --r;
                while (l < r && nums[l]==nums[l-1]) ++l;
                while (l < r && nums[r]==nums[r+1]) --r;
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
    
    int arr[] = {-1, 0, 1, 2, -1, -1};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    
    auto res = sol.threeSum(v);
    printVectors(res);
    
    return 0;
}
