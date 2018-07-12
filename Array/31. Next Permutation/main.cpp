//
//  main.cpp
//  31. Next Permutation
//
//  Created by 边俊林 on 2018/7/12.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ---------------------------------------------------------- *\
 https://leetcode-cn.com/problems/next-permutation/description/
\* ---------------------------------------------------------- */

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
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0) { return; }
        
        for (int i = (int)nums.size()-1; i >= 0; --i) {
            for (int j = (int)nums.size()-1; j > i; --j) {
                if (nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                    sort(nums.begin()+i+1, nums.end());
                    return;
                }
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};

// Tool Function List
void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
    
    int arr[] = {1, 2, 3, 5, 5};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    
    sol.nextPermutation(v);
    printVector(v);
    
    return 0;
}
