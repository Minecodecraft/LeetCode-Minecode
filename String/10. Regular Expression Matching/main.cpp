//
//  main.cpp
//  10. Regular Expression Matching
//
//  Created by 边俊林 on 2019/7/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/regular-expression-matching/
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
// Recursive Solution
/*
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        if (p.length() > 1 && p[1] == '*')
            return isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p);
        else
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
    }
};
 */
// DP Solution
class Solution {
public:
    bool isMatch(string s, string p) {
        auto n = s.length(), m = p.length();
        // dp[i][j] means s[i-1] matchs p[i-1]
        vector<vector<bool>> dp = vector<vector<bool>>(n+1, vector<bool>(m+1, false));
        // Init
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i)
            dp[0][i] = false;
        // Process the case that not matched before like [s = "eeeee"  p = "a*b*c*d*e*"]
        for (int i = 2; i <= m; ++i)
            dp[0][i] = p[i-1] == '*' && dp[0][i-2];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j-1] == '*')
                    dp[i][j] = dp[i][j-2] || j > 1 && (s[i-1] == p[j-2] || '.' == p[j-2]) && dp[i-1][j];
                else
                    dp[i][j] = (s[i-1] == p[j-1] || s[i-1] == '.') && dp[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};


int main() {
    Solution sol = Solution();
//    string s = "aa";
//    string p = "a";
//    string s = "aa";
//    string p = "a*";
//    string s = "ab";
//    string p = ".*";
//    string s = "aab";
//    string p = "c*a*b";
//    string s = "mississippi";
//    string p = "mis*is*p*.";
//    string s = "ab";
//    string p = ".*c";
//    string s = "ab";
//    string p = ".*c*";
//    string s = "bbbba";
//    string p = ".*a*a";
    string s = "aaaa";
    string p = "....";
    auto res = sol.isMatch(s, p);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
