//
//  main.cpp
//  844. Backspace String Compare
//
//  Created by 边俊林 on 2019/10/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/backspace-string-compare/
\* ------------------------------------------------------ */

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

/// Solution:
//
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s1 = "", s2 = "";
        for (auto& ch: S)
            if (ch == '#' && s1.length()) s1.pop_back();
            else if (ch != '#') s1.push_back(ch);

        for (auto& ch: T)
        if (ch == '#' && s2.length()) s2.pop_back();
        else if (ch != '#') s2.push_back(ch);
        return s1 == s2;
    }
};

int main() {
    Solution sol = Solution();
    string s = "ab#c", t = "ad#c";
    bool res = sol.backspaceCompare(s, t);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
