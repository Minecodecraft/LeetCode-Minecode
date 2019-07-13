//
//  main.cpp
//  5. Longest Palindromic Substring
//
//  Created by Minecode on 2019/7/13.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/longest-palindromic-substring/
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
    string longestPalindrome(string s) {
        string mcr;
        for (int i = 0; i < s.length(); ++i) {
            mcr += "#" + s.substr(i, 1);
        }
        mcr += "#";
        auto L = mcr.length();
        
        int beg, maxlen, l, r;
        beg = maxlen = l = r = 0;
        for (int i = 0; i < L; i++) {
            l = r = i;
            while (l >= 0 && r < L && mcr[l] == mcr[r]) {
                l--;
                r++;
            }
            int thislen;
            if (mcr[i] == '#') thislen = (r-l-2) >> 1;
            else thislen = (r-l-1) >> 1;
            if (thislen > maxlen) {
                maxlen = thislen;
                beg = (l+2) >> 1;
            }
        }
        return s.substr(beg, maxlen);
    }
};

int main() {
    Solution sol = Solution();
//    string s = "babad";
//    string s = "cbbd";
//    string s = "";
    string s = "abcdedcba";
    auto res = sol.longestPalindrome(s);
    cout << res << endl;
    return 0;
}
