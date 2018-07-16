//
//  main.cpp
//  41. First Missing Positive
//
//  Created by 边俊林 on 2018/7/16.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ---------------------------------------------------------------- *\
 https://leetcode-cn.com/problems/first-missing-positive/description/
\* ---------------------------------------------------------------- */

#include <map>
#include <set>
#include <queue>
#include <stack>
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
    int firstMissingPositive(vector<int>& nums) {
        int n = (int)nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (nums[i]>0 && nums[i]<n && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
                i--;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i+1) return i + 1;
        }
        return n + 1;
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
    
    int arr[] = {-1, 4, 2, 1, 9, 10};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    
    int res = sol.firstMissingPositive(v);
    cout << res << endl;
    
    return 0;
}
