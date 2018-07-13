//
//  main.cpp
//  35. Search Insert Position
//
//  Created by 边俊林 on 2018/7/13.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ----------------------------------------------------------------- *\
 https://leetcode-cn.com/problems/search-insert-position/description/
\* ----------------------------------------------------------------- */

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
// Dichotomy algorithm

/// Tips:
//

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        
        int l = 0, r = (int)nums.size()-1;
        int mid = 0;
        while (l <= r) {
            mid = (l+r) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (l == r) {
                return nums[l] > target ? l : l+1;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return mid;
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
    
    int arr[] = {3, 5, 7, 9, 10};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    int target = 8;
    
    int res = sol.searchInsert(v, target);
    cout << res << endl;
    
    return 0;
}
