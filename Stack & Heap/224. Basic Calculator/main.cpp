//
//  main.cpp
//  224. Basic Calculator
//
//  Created by 边俊林 on 2019/10/2.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/basic-calculator/
\* ------------------------------------------------------ */

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
    int calculate(string s) {
        vector<string> exp = _resolveExp(s);
        stack<int> calst;
        for (string &str: exp) {
            if (op.count(str) > 0) {
                int n2 = calst.top(); calst.pop();
                int n1 = calst.top(); calst.pop();
                calst.push(op[str](n1, n2));
            } else
                calst.push(stoi(str));
        }
        return calst.top();
    }

private:
    unordered_map<string, function<int (int, int)>> op = {
        {"+", [] (int a, int b) { return a + b; }},
        {"-", [] (int a, int b) { return a - b; }},
        {"*", [] (int a, int b) { return a * b; }},
        {"/", [] (int a, int b) { return a / b; }}
    };

    vector<string> _resolveExp(const string& s) {
        vector<string> exp;
        stack<string> ops;
        int l = 0, r = l;
        while (l < s.length()) {
            r = l;
            if (s[r] == '(') {
                ops.push(s.substr(r, 1));
            } else if (s[r] == ')') {
                while (ops.top() != "(")
                    exp.push_back(ops.top()), ops.pop();
                ops.pop();
            } else if (s[r] == '+' || s[r] == '-' || s[r] == '*' || s[r] == '/') {
                string curop = s.substr(r, 1);
                while (!ops.empty() && !isGreater(curop, ops.top()))
                    exp.push_back(ops.top()), ops.pop();
                ops.push(curop);
            } else if (isdigit(s[r])) {
                while (r < s.length() && isdigit(s[r])) ++r;
                string numstr = s.substr(l, (r--)-l);
                exp.push_back(numstr);
            }
            l = r = r + 1;
        }
        while (!ops.empty())
            exp.push_back(ops.top()), ops.pop();
        return exp;
    }

    bool isGreater(string a, string b) {
        if ((a == "*" || a == "/") && (b == "+" || b == "-"))
            return true;
        return b == "(";
    }
};

int main() {
    Solution sol = Solution();
//    string s = "1 + 1";
//    string s = " 2-1 + 2 ";
    string s = "(1+(4+5+2)-3)+(6+8)";
    int res = sol.calculate(s);
    cout << res << endl;
    return 0;
}
