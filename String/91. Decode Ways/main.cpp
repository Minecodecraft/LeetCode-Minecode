//
//  main.cpp
//  91. Decode Ways
//
//  Created by 边俊林 on 2019/7/30.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/decode-ways/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
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
    int numDecodings(string s) {
        auto n = s.length();
        // dp[i] means the decode ways of s[i-1]
        vector<int> dp (n+1, 0);
        dp[0] = 1;
        int cnt;
        for (int i = 1; i <= n; ++i) {
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            if (i > 1 && ((s[i-2] == '1') || (s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6'))) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol = Solution();
//    string s = "12";
//    string s = "226";
    string s = "10";
    auto res = sol.numDecodings(s);
    cout << res << endl;
    return 0;
}
