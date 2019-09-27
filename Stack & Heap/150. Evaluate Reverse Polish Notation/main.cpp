//
//  main.cpp
//  150. Evaluate Reverse Polish Notation
//
//  Created by 边俊林 on 2019/9/27.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/evaluate-reverse-polish-notation/
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
// Solution 1: Stack with recursive solution, 20ms
/*
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (auto &elem: tokens)
            st.push(elem);
        if (st.empty()) return 0;
        if (!isOperator(st.top())) return stoi(st.top());
        cal(st);
        return stoi(st.top());
    }

private:
    void cal(stack<string>& st) {
        string sign = st.top(); st.pop();
        if (isOperator(st.top()))
            cal(st);
        int n2 = stoi(st.top());
        st.pop();
        if (isOperator(st.top()))
            cal(st);
        int n1 = stoi(st.top());
        st.pop();
        int res = 0;
        if (sign == "+")
            res = n1 + n2;
        else if (sign == "-")
            res = n1 - n2;
        else if (sign == "*")
            res = n1 * n2;
        else if (sign == "/")
            res = n2 == 0 ? 0 : n1 / n2;
        st.push(to_string(res));
    }

    bool isOperator(const string &str) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }
};
 */

// Solution 2: Use lambda map, 12ms 👍
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string &str: tokens) {
            if (op.count(str) > 0) {
                int n2 = st.top(); st.pop();
                int n1 = st.top(); st.pop();
                st.push(op[str](n1, n2));
            } else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }

private:
    unordered_map<string, function<int (int, int)>> op = {
        {"+", [] (int a, int b) { return a + b; } },
        {"-", [] (int a, int b) { return a - b; } },
        {"*", [] (int a, int b) { return a * b; } },
        {"/", [] (int a, int b) { return a / b; } },
    };
};

int main() {
    Solution sol = Solution();
    vector<string> tokens = {
//        "2", "1", "+", "3", "*"
//        "4", "13", "5", "/", "+"
//        "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"
        "18"
    };
    int res = sol.evalRPN(tokens);
    cout << res << endl;
    return 0;
}
