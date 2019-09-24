//
//  main.cpp
//  1004. Max Consecutive Ones III
//
//  Created by 边俊林 on 2019/9/24.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/max-consecutive-ones-iii/
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
    int longestOnes(vector<int>& A, int K) {
        int l = 0, res = 0, tot = 0;
        for (int r = 0; r < A.size(); ++r) {
            if (A[r] == 0) {
                while (tot >= K) if (A[l++] == 0) --tot;
                ++tot;
            }
            res = max(r-l+1, res);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1,1,1,0,0,0,1,1,1,1,0
        0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1
    };
//    int K = 2;
    int K = 3;
    int res = sol.longestOnes(nums, K);
    cout << res << endl;
    return 0;
}
