//
//  main.cpp
//  392. Is Subsequence
//
//  Created by 边俊林 on 2019/9/6.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/is-subsequence/
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
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for (auto ch: t) {
            if (s[idx] == ch)
                ++idx;
            if (idx >= s.length()) break;
        }
        return idx == s.length();
    }
};

int main() {
    Solution sol = Solution();
    string s = "r";
    string t = "ahbgdc";
    bool res = sol.isSubsequence(s, t);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
