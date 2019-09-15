//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2019/9/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
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
    string reverseParentheses(string s) {
        int len = s.length();
        stack<string> st;
        int i = 0;
        while (i < len) {
            if (s[i] == '(') {
                st.push(s.substr(i, 1));
                ++i;
            } else if (isalpha(s[i])) {
                int r = i;
                while (isalpha(s[r])) ++r;
                st.push(s.substr(i, r-i));
                i = r;
            } else if (s[i] == ')') {
                string buffer;
                while (st.top() != "(") {
                    buffer.insert(0, st.top());
                    st.pop();
                }
                reverse(buffer.begin(), buffer.end());
                st.pop();
                st.push(buffer);
                ++i;
            }
        }
        string res;
        while (!st.empty() && st.top() != "(") {
            res.insert(0, st.top());
            st.pop();
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    string s = "(ed(et(oc))el)";
//    string s = "(abcd)";
//    string s = "(u(love)i)";
//    string s = "a(bcdefghijkl(mno)p)q";
    string res = sol.reverseParentheses(s);
    cout << res << endl;
    return 0;
}
