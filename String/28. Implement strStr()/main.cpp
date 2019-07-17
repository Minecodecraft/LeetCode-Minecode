//
//  main.cpp
//  28. Implement strStr()
//
//  Created by Minecode on 2019/7/17.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/implement-strstr/
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
// KMP Solution
class Solution {
public:
    int strStr(string haystack, string needle) {
        auto slen = haystack.size(), plen = needle.size();
        if (slen == 0) return plen == 0 ? 0 : -1;
        if (plen == 0) return 0;
        haystack.insert(haystack.begin(), '#');
        needle.insert(needle.begin(), '#');
        int j = 0;
        for (int i = 2; i <= plen; ++i) {
            while (j && needle[i] != needle[j+1])
                j = kmp[j];
            if (needle[j+1] == needle[i])
                ++j;
            kmp[i] = j;
        }
        j = 0;
        for (int i = 1; i <= slen; ++i) {
            while (j>0 && needle[j+1] != haystack[i])
                j = kmp[j];
            if (needle[j+1] == haystack[i])
                ++j;
            if (j == plen)
                return i-plen;
        }
        return -1;
    }
    
private:
    const static int MAXN = 1e5+10;
    int kmp[MAXN];
};

int main() {
    Solution sol = Solution();
    string s = "hello";
    string p = "ll";
//    string s = "aaaaaaa";
//    string p = "bba";
//    string s = "abeabceabcde";
//    string p = "abcde";
//    string s = "";
//    string p = "";
    auto res = sol.strStr(s, p);
    cout << res << endl;
    return 0;
}
