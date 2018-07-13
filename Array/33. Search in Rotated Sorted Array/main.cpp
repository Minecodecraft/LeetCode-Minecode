//
//  main.cpp
//  33. Search in Rotated Sorted Array
//
//  Created by 边俊林 on 2018/7/13.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ------------------------------------------------------------------------ *\
 https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
\* ------------------------------------------------------------------------ */

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
// Dichototmy Algorithm

/// Tips:
// Though the list is ratated, but there's must a section is ascending orider. [l, mid] or [r, mid], mid is the midimum number of the section.
// So we can use dichotomy algorithm to sperate the section. And just which is the ascending ordered secntion.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        
        int mid;
        int l = 0, r = (int)nums.size()-1;
        while (l <= r) {
            mid = (l+r) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < nums[r]) {
                if (nums[mid]<=target && nums[r]>=target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (nums[l]<=target && nums[mid]>=target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
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
    
    int arr[] = {1, 3};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    int target = 3;
    
    int res = sol.search(v, target);
    cout << res << endl;
    
    return 0;
}
