//
//  main.cpp
//  736. Parse Lisp Expression
//
//  Created by Jaylen Bian on 12/15/20.
//  Copyright © 2020 边俊林. All rights reserved.
//

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
    int helper(string exp, unordered_map<string, vector<int>>& mp) {
        // If exp is a number of variable
        if (exp[0] == '-' || (exp[0] >= '0' && exp[0] <= '9'))
            return stoi(exp);
        else if (exp[0] != '(')
            return mp[exp].back();

        // If exp is a expr
        exp = exp.substr(1, exp.length()-2);
        int start = 0;
        string cmd = parse(exp, start);
        if (cmd == "add") {
            return helper(parse(exp, start), mp) + helper(parse(exp, start), mp);
        } else if (cmd == "mult") {
            return helper(parse(exp, start), mp) * helper(parse(exp, start), mp);
        } else if (cmd == "let") {
            vector<string> vars;
            while (start < exp.length()) {
                string var = parse(exp, start);
                if (start > exp.length()) {
                    int res = helper(var, mp);
                    for (auto theVar: vars)
                        mp[theVar].pop_back();
                    return res;
                }
                vars.push_back(var);
                mp[var].push_back(helper(parse(exp, start), mp));
            }
        }
        return 0;
    }

    /// If exp = (x1 x2 (x3 x4)), return the (x1 x2 (x3 x4))
    /// If exp = x1 x2 (x3 x4), return x1
    string parse(string exp, int& start) {
        int tmps = start, end = start + 1;
        if (exp[start] == '(') {
            int blkCnt = 1;
            while (blkCnt > 0) {
                if (exp[end] == ')')
                    --blkCnt;
                else if (exp[end] == '(')
                    ++blkCnt;
                ++end;
            }
        } else {
            while (end < exp.length() && exp[end] != ' ')
                ++end;
        }
        start = end + 1;
        return exp.substr(tmps, end - tmps);
    }

public:
    int evaluate(string exp) {
        unordered_map<string, vector<int>> mp;
        return helper(exp, mp);
    }
};

int main() {
    Solution sol = Solution();
    vector<string> exps = {
        "(add 1 2)",
        "(mult 3 (add 2 3))",
        "(let x 2 (mult x 5))",
        "(let x 2 (mult x (let x 3 y 4 (add x y))))",
        "(let x 3 x 2 x)",
        "(let x 1 y 2 x (add x y) (add x y))",
        "(let x 2 (add (let x 3 (let x 4 x)) x))",
        "(let a1 3 b2 (add a1 1) b2)"
        "(mult -1 2)"
    };
    for (string exp: exps) {
        int res = sol.evaluate(exp);
        cout << res << endl;
    }
    return 0;
}
