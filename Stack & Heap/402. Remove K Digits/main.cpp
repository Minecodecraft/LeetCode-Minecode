//
//  main.cpp
//  402. Remove K Digits
//
//  Created by 边俊林 on 2019/10/6.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/remove-k-digits/
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
    string removeKdigits(string num, int k) {
        int idx = 0, len = num.length();
        stack<int> st;
        while (idx < len) {
            while (!st.empty() && st.top() > num[idx]-'0' && k > 0)
                st.pop(), --k;
            st.push(num[idx] - '0');
            ++idx;
        }
        while (k > 0 && !st.empty())
            st.pop(), --k;
        string res = "";
        while (!st.empty()) {
            res.insert(res.begin(), st.top()+'0');
            st.pop();
        }
        idx = 0;
        while (idx < res.length() && res[idx] == '0') ++idx;
        res = string(res.begin()+idx, res.end());
        return res.empty() ? "0" : res;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "1432219";
//    int k = 3;
    string s = "10200";
    int k = 1;
//    string s = "10";
//    int k = 2;
//    string s = "9";
//    int k = 1;
    string res = sol.removeKdigits(s, k);
    cout << res << endl;
    return 0;
}
