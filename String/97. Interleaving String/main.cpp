//
//  main.cpp
//  97. Interleaving String
//
//  Created by 边俊林 on 2019/7/31.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/interleaving-string/
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
    bool isInterleave(string s1, string s2, string s3) {
        auto la = s1.length(), lb = s2.length(), lc = s3.length();
        // dp[i][j] means s1[0,i-1) and s2[0, j-1) can interleaving to s3[0, i+j-2)
        vector<vector<bool>> dp = vector<vector<bool>>(la+1, vector<bool> (lb+1, false));

        if (s1.empty()) return s2 == s3;
        if (s2.empty()) return s1 == s3;
        if (la + lb < lc) return false;
        dp[0][0] = true;
        for (int i = 1; i <= la; ++i) {
            if (s1[i-1] != s3[i-1]) break;
            dp[i][0] = true;
        }
        for (int i = 1; i <= lb; ++i) {
            if (s2[i-1] != s3[i-1]) break;
            dp[0][i] = true;
        }
        for (int i = 1; i <= la; ++i) {
            for (int j = 1; j <= lb; ++j) {
                if ((dp[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                    (dp[i][j-1] && s2[j-1] == s3[i+j-1])) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[la][lb];
    }
};

int main() {
    Solution sol = Solution();
//    string s1 = "aabcc";
//    string s2 = "dbbca";
//    string s3 = "aadbbcbcac";
//    string s3 = "aadbbbaccc";
//    string s1 = "ace";
//    string s2 = "bdf";
//    string s3 = "abcdef";
    string s1 = "a";
    string s2 = "b";
    string s3 = "aba";
    auto res = sol.isInterleave(s1, s2, s3);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
