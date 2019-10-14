//
//  main.cpp
//  856. Score of Parentheses
//
//  Created by 边俊林 on 2019/10/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
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
    int scoreOfParentheses(string S) {
        stack<int> st;
        for (auto& ch: S) {
            if (ch == '(')
                st.push(-1);
            else if (ch == ')') {
                int num = 0;
                while (st.top() != -1)
                    num += st.top(), st.pop();
                st.pop();
                st.push(num == 0 ? 1 : 2 * num);
            }
        }
        int res = 0;
        while (st.size())
            res += st.top(), st.pop();
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "()";
//    string s = "(())";
//    string s = "()()";
    string s = "(()(()))";
    int res = sol.scoreOfParentheses(s);
    cout << res << endl;
    return 0;
}
