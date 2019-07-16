//
//  main.cpp
//  20. Valid Parentheses
//
//  Created by 边俊林 on 2019/7/16.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/valid-parentheses/
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
    bool isValid(string s) {
        vector<char> prefix = {'(', '[', '{'};
        vector<char> subfix = {')', ']', '}'};
        stack<char> st;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            int idx = indexOf(prefix, ch);
            if (idx != -1) {
                st.push(ch);
            } else {
                idx = indexOf(subfix, ch);
                if (st.empty() || st.top() != prefix[idx])
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
private:
    int indexOf(vector<char> &vec, char &ch) {
        for (int i = 0; i < vec.size(); ++i)
            if (vec[i] == ch) return i;
        return -1;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "()";
//    string s = "()[]{}";
//    string s = "(]";
//    string s = "{[]}";
    string s = "]";
    auto res = sol.isValid(s);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
