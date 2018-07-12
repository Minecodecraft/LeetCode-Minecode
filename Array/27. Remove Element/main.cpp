//
//  main.cpp
//  27. Remove Element
//
//  Created by 边俊林 on 2018/7/12.
//  Copyright © 2018 minecode. All rights reserved.
//

/* --------------------------------------------------------- *\
 https://leetcode-cn.com/problems/remove-element/description/
\* --------------------------------------------------------- */

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
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) { return 0;}
        
        int p = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) continue;
            nums[p++] = nums[i];
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
    
    int arr[] = {0, 1, 2, 2, 3, 0, 4, 2};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    int val = 2;
    
    int res = sol.removeElement(v, val);
    cout << res << endl;
    
    return 0;
}
