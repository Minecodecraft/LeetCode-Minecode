//
//  main.cpp
//  26. Remove Duplicates from Sorted Array
//
//  Created by Minecode on 2018/7/12.
//  Copyright © 2018年 minecode. All rights reserved.
//

/* ----------------------------------------------------------------------------- *\
 https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/
\* ----------------------------------------------------------------------------- */

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
// Just record the last maximum number and the length of appropriate number.

/// Tips:
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int flagNum = nums[0]-1;
        int p = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > flagNum) {
                flagNum = nums[i];
                nums[p] = flagNum;
                p++;
            }
        }
        return p;
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
    
    int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    
    int res = sol.removeDuplicates(v);
    cout << res << endl;
    
    return 0;
}
