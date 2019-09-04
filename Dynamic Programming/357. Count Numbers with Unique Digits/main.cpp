//
//  main.cpp
//  357. Count Numbers with Unique Digits
//
//  Created by 边俊林 on 2019/9/4.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/count-numbers-with-unique-digits/
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
    int countNumbersWithUniqueDigits(int n) {
        if (n <= 0) return 1;
        vector<int> dp (n+1, 0);
        dp[1] = 10;
        for (int i = 2; i <= n; ++i) {
            dp[i] = 9;
            for (int j = 9; j >= (9-i+2); --j) {
                dp[i] *= j;
            }
            dp[i] += dp[i-1];
        }
        return dp[n];
    }
};

int main() {
    Solution sol = Solution();
    int n = 0;
    int res = sol.countNumbersWithUniqueDigits(n);
    cout << res << endl;
    return 0;
}
