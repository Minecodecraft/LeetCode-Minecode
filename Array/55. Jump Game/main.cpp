//
//  main.cpp
//  55. Jump Game
//
//  Created by 边俊林 on 2018/7/19.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/jump-game/description/
\* ------------------------------------------------------ */

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
// Determin the farest point we can go, and judgr if it large than the total length.

/// Tips:
//

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int position = 0, farest = 0;
        for (int i = 0; i < nums.size() && i <= farest; ++i) {
            farest = max(farest, i+nums[i]);
            if (i == position) { position = farest; }
        }
        return farest >= nums.size()-1;
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        vector<int> index(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            index[i] = nums[i] + i;
        }
        int maxIndex = index[0];
        int idx = 0;
        while (idx < index.size() && idx <= maxIndex) {
            if (maxIndex < index[idx]) { maxIndex = index[idx]; }
            idx++;
        }
        return idx == index.size();
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
    Solution2 sol = Solution2();
    
    vector<int> v {2,3,1,1,4};
    
    
    auto res = sol.canJump(v);
    cout << res << endl;
    
    return 0;
}
