//
//  main.cpp
//  647. Palindromic Substrings
//
//  Created by 边俊林 on 2019/8/17.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/palindromic-substrings/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    int countSubstrings(string s) {
        int cnt = s.length();
        for (int i = 0; i < s.length(); ++i) {
            int level = 1;
            while (i+level < s.length() && i-level >= 0 && s[i-level] == s[i+level]) {
                ++cnt; ++level;
            }
        }
        for (int i = 0; i < s.length(); ++i) {
            int level = 1;
            while (i+level < s.length() && i-level+1 >= 0 && s[i-level+1] == s[i+level]) {
                ++cnt; ++level;
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "abc";
    string s = "aaa";
//    string s = "aaaaa";
    int res = sol.countSubstrings(s);
    cout << res << endl;
    return 0;
}
