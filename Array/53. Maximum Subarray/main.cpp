//
//  main.cpp
//  53. Maximum Subarray
//
//  Created by 边俊林 on 2018/7/18.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ---------------------------------------------------------- *\
 https://leetcode-cn.com/problems/maximum-subarray/description/
\* ---------------------------------------------------------- */

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
// Dynamic Programming

/// Tips:
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()+1];
        int maxx = INT_MIN;
        
        dp[0] = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            dp[i] = max(dp[i-1]+nums[i-1], nums[i-1]);
            maxx = max(dp[i], maxx);
        }
        return maxx;
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
    
    vector<int> v {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int res = sol.maxSubArray(v);
    cout << res << endl;
    return 0;
}
