//
//  main.cpp
//  3. Longest Substring Without Repeating Characters
//
//  Created by 边俊林 on 2019/7/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/longest-substring-without-repeating-characters/
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
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        set<int> ext;
        int l, r, res;
        l = r = res = 0;
        while (l <= r) {
            while (r < len && ext.count(s[r]) == 0)
                ext.insert(s[r++]);
            res = max(res, r-l);
            while (l < len && s[l] != s[r])
                ext.erase(s[l++]);
            ext.erase(s[l++]);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "pwwkew";
//    string s = "abcabcbb";
//    string s = "bbbbb";
    string s = "";
    auto res = sol.lengthOfLongestSubstring(s);
    cout << res << endl;
    return 0;
}
