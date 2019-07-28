//
//  main.cpp
//  76. Minimum Window Substring
//
//  Created by 边俊林 on 2019/7/28.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/minimum-window-substring/
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
    string minWindow(string s, string t) {
        unordered_map<int, int> mp;
        int l, r, beg, mindis, last;
        l = r = beg = 0;
        last = t.length();
        mindis = INT_MAX;
        for (int i = 0; i < t.length(); ++i)
            mp[t[i]]++;
        while (r < s.length()) {
            if (mp[s[r]] > 0) last--;
            mp[s[r++]]--;
            while (last == 0) {
                if (r-l < mindis) {
                    mindis = r-l;
                    beg = l;
                }
                if (mp[s[l]] == 0) last++;
                mp[s[l++]]++;
            }
        }
        if (mindis == INT_MAX)
            return "";
        return s.substr(beg, mindis);
    }
};

int main() {
    Solution sol = Solution();
//    string s = "ADOBECODEBANC";
//    string t = "ABC";
//    string s = "";
//    string t = "ABC";
    string s = "ABABABABABABABBABABABBABABDDDDDDDDDDDDDC";
    string t = "ABC";
    auto res = sol.minWindow(s, t);
    cout << res << endl;
    return 0;
}
