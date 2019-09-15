//
//  main.cpp
//  516. Longest Palindromic Subsequence
//
//  Created by 边俊林 on 2019/9/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/longest-palindromic-subsequence/
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
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<vector<int>> dp (len, vector<int> (len, 1));

        for (int i = 2; i <= len; ++i) {
            for (int j = 0; j <= len-i; ++j) {
                int l = j, r = j + i - 1;
                dp[l][r] = max(dp[l][r-1], dp[l+1][r]);
                if (s[l] == s[r])
                    dp[l][r] = max(dp[l][r], i == 2 ? 2 : dp[l+1][r-1]+2);
            }
        }
        return dp[0][len-1];
    }
};

int main() {
    Solution sol = Solution();
//    string s = "bbbab";
//    string s = "cbbd";
    string s = "abc";
    int res = sol.longestPalindromeSubseq(s);
    cout << res << endl;
    return 0;
}
