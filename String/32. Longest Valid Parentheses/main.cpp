//
//  main.cpp
//  32. Longest Valid Parentheses
//
//  Created by 边俊林 on 2019/7/19.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/longest-valid-parentheses/
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
    int longestValidParentheses(string s) {
        stack<int> st;
        auto len = s.length();
        for (int i = 0; i < len; ++i) {
            if (s[i] == ')') {
                if (!st.empty()) {
                    if (s[st.top()] == '(') st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
            else st.push(i);
        }
        if (st.empty()) return len;
        int res = 0;
        int l = 0, r = len;
        while (!st.empty()) {
            l = st.top(); st.pop();
            res = max(res, r - l - 1);
            r = l;
        }
        res = max(res, l);
        return res;
    }
};

int main() {
    Solution sol = Solution();
    string s = ")()())";
    auto res = sol.longestValidParentheses(s);
    cout << res << endl;
    return 0;
}
