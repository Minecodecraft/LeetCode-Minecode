//
//  main.cpp
//  96. Unique Binary Search Trees
//
//  Created by 边俊林 on 2019/8/19.
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
    int numTrees(int n) {
        vector<int> dp (n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol = Solution();
//    int n = 19;
    int n = 3;
//    int n = 2;
//    int n = 1;
//    int n = 0;
    int res = sol.numTrees(n);
    cout << res << endl;
    return 0;
}
