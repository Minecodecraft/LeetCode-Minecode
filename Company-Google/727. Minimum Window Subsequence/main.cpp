//
//  main.cpp
//  727. Minimum Window Subsequence
//
//  Created by Jaylen Bian on 12/6/20.
//  Copyright © 2020 边俊林. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution: 1: Use simple dp
//
/**
class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.length(), m = T.length();
        // dp[i][j]=k means k is the largest index in S[0:i] that T[0:j] is the subsequence of this S substring.
        vector<vector<int>> dp = vector<vector<int>> (n, vector<int> (m, -1));

        for (int i = 0; i < n; ++i)
            if (S[i] == T[0])
                dp[i][0] = i;

        for (int j = 1; j < m; ++j) {
            int match = -1;
            for (int i = 0; i < n; ++i) {
                if (match != -1 && S[i] == T[j])
                    dp[i][j] = match;
                if (dp[i][j-1] != -1)
                    match = dp[i][j-1];
            }
        }

        int beg = -1, len = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (dp[i][m-1] != -1 && i - dp[i][m-1] + 1 < len) {
                beg = dp[i][m-1];
                len = i - dp[i][m-1] + 1;
            }
        }
        if (beg == -1)
            return "";
        return S.substr(beg, len);
    }
};
 */

// Solution 2: Use dp with rolling array optimization.
class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.length(), m = T.length();
        // use rolling array, dp[i][j]=k means k is the largest index in S[0:i] that T[0:j] is the subsequence of this S substring.
        vector<int> dp (n, -1);
        for (int i = 0; i < n; ++i)
            if (S[i] == T[0])
                dp[i] = i;
        for (int i = 1; i < m; ++i) {
            int matched = -1;
            vector<int> tmp (n, -1);
            for (int j = 0; j < n; ++j) {
                if (matched != -1 && S[j] == T[i])
                    tmp[j] = matched;
                if (dp[j] != -1)
                    matched = dp[j];
            }
            swap(tmp, dp);
        }

        int beg = -1, len = INT_MAX;
        for (int i = 0; i < n; ++i)
            if (dp[i] != -1 && i - dp[i] + 1 < len)
                beg = dp[i], len = i - dp[i] + 1;
        return beg == -1 ? "" : S.substr(beg, len);
    }
};

int main() {
    Solution sol = Solution();
    string S = "abcdebdde", T = "bde";
    string res = sol.minWindow(S, T);
    cout << res << endl;
    return 0;
}
