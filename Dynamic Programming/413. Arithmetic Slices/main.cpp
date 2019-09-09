//
//  main.cpp
//  413. Arithmetic Slices
//
//  Created by 边俊林 on 2019/9/9.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/arithmetic-slices/
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
//
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        vector<int> dp (n+1, 0);
        if (A[2] - A[1] == A[1] - A[0]) dp[2] = 1;
        int res = dp[2];
        for (int i = 3; i < n; ++i) {
            if (A[i]-A[i-1] == A[i-1]-A[i-2])
                dp[i] = dp[i-1]+1;
            res += dp[i];
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {
        1,2,3,4
    };
    int res = sol.numberOfArithmeticSlices(arr);
    cout << res << endl;
    return 0;
}
