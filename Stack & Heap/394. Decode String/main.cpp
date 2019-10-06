//
//  main.cpp
//  394. Decode String
//
//  Created by 边俊林 on 2019/10/5.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/decode-string/
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
    string decodeString(string s) {
        int l = 0, r = l;
        stack<string> st;
        bool lastIsNum = false;
        while (l < s.length()) {
            if (s[r] == '[') {
                st.push("[");
                ++r;
                lastIsNum = false;
            } else if (isalpha(s[r])) {
                if (!lastIsNum) st.push(to_string(1));
                while (r<s.length() && isalpha(s[r])) ++r;
                st.push(s.substr(l, r-l));
                lastIsNum = false;
            } else if (s[r] == ']') {
                string res = "";
                while (!st.empty() && st.top() != "[") {
                    string rawstr = st.top(); st.pop();
                    int times = stoi(st.top()); st.pop();
                    while (times-- > 0)
                        res.insert(0, rawstr);
                }
                st.pop();
                st.push(res);
                ++r;
                lastIsNum = false;
            } else if (isdigit(s[r])) {
                while (r<s.length() && isdigit(s[r])) ++r;
                st.push(s.substr(l, r-l));
                lastIsNum = true;
            }
            l = r;
        }
        string res = "";
        while (!st.empty()) {
            string rawstr = st.top(); st.pop();
            int times = stoi(st.top()); st.pop();
            while (times-- > 0)
                res.insert(0, rawstr);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "3[a]2[bc]";
//    string s = "3[a2[c]]";
    string s = "2[abc]3[cd]ef";
    string res = sol.decodeString(s);
    cout << res << endl;
    return 0;
}
