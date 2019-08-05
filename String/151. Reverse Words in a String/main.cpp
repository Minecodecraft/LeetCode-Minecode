//
//  main.cpp
//  151. Reverse Words in a String
//
//  Created by 边俊林 on 2019/8/5.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/reverse-words-in-a-string/
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
    string reverseWords(string s) {
        stack<string> st;
        int l = 0, r;
        while (l < s.length()) {
            while (l < s.length() && s[l] == ' ') ++l;
            r = l;
            while (r < s.length() && s[r] != ' ') ++r;
            string str = s.substr(l, r-l);
            if (!str.empty())
                st.push(str);
            l = r+1;
        }
        string res;
        while (!st.empty()) {
            string tmp = st.top();
            st.pop();
            res += tmp;
            if (!st.empty())
                res += ' ';
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    string s = "the sky is blue";
//    string s = "     the sky is blue   ";
//    string s = "           ";
    auto res = sol.reverseWords(s);
    cout << res << endl;
    return 0;
}
//
