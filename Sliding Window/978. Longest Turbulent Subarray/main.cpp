//
//  main.cpp
//  978. Longest Turbulent Subarray
//
//  Created by 边俊林 on 2019/9/19.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
 \* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int res = 0;
        for (int i = 0, cnt = 0; i < A.size()-1; ++i, cnt *= -1) {
            if (A[i] > A[i+1]) cnt = cnt > 0 ? cnt+1 : 1;
            else if (A[i] < A[i+1]) cnt = cnt < 0 ? cnt-1 : -1;
            else cnt = 0;
            res = max(res, abs(cnt));
        }
        return res + 1;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        9,4,2,10,7,8,8,1,9
//        4,8,12,16
//        100
//        0,1,1,0,1,0,1,1,0,0
        2,0,2,4,2,5,0,1,2,3
    };
    int res = sol.maxTurbulenceSize(nums);
    cout << res << endl;
    return 0;
}
