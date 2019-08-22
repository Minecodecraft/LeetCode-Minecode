//
//  main.cpp
//  132. Palindrome Partitioning II
//
//  Created by 边俊林 on 2019/8/21.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/palindrome-partitioning-ii/
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
    int minCut(string s) {
        int len = s.length();
        vector<int> dp (len+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (isPalindrome(s, j-1, i-1)) {
                    dp[i] = min(dp[i], dp[j-1] + 1);
                }
            }
        }
        return dp[len]-1;
    }

private:
    bool isPalindrome(const string& s, int beg, int end) {
        int l = beg, r = end;
        while (l <= r && s[l] == s[r]) {
            ++l, --r;
        }
        return l > r;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "aab";
//    string s = "";
    string s = "aaabaaacddadde";
    auto res = sol.minCut(s);
    cout << res << endl;
    return 0;
}
