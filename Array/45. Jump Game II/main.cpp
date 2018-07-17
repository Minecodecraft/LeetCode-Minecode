//
//  main.cpp
//  45. Jump Game II
//
//  Created by 边俊林 on 2018/7/17.
//  Copyright © 2018 minecode. All rights reserved.
//

/* -------------------------------------------------------- *\
 https://leetcode-cn.com/problems/jump-game-ii/description/
\* -------------------------------------------------------- */

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
    int jump(vector<int>& nums) {
        int position = 0, farest = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            farest = max(farest, i+nums[i]);
            if (i == position) {
                cnt++;
                position = farest;
            }
        }
        return cnt;
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
    
    int arr[] = {2, 3, 1, 1, 4};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    
    int res = sol.jump(v);
    cout << res << endl;
    
    return 0;
}
