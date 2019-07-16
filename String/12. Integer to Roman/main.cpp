//
//  main.cpp
//  12. Integer to Roman
//
//  Created by 边俊林 on 2019/7/16.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    Solution() {
        syms = {
            Symbol('I', 1, ' ', INT_MAX),
            Symbol('V', 5, 'I', 4),
            Symbol('X', 10, 'I', 9),
            Symbol('L', 50, 'X', 40),
            Symbol('C', 100, 'X', 90),
            Symbol('D', 500, 'C', 400),
            Symbol('M', 1000, 'C', 900)
        };
        for (int i = 0; i < syms.size(); ++i) {
            if (i > 0) syms[i].prv = &syms[i-1];
            if (i < syms.size()-1) syms[i].nxt = &syms[i+1];
        }
    }

    string intToRoman(int num) {
        if (num <= 0) return "";
        string res;
        int p = syms.size()-1;
        while (p >= 0 && num) {
            while (num >= syms[p].val) {
                res.push_back(syms[p].sym);
                num -= syms[p].val;
            }
            if (num >= syms[p].subval) {
                res.push_back(syms[p].subsym);
                res.push_back(syms[p].sym);
                num -= syms[p].subval;
            }
            p--;
        }
        return res;
    }

private:
    typedef struct Symbol {
        char sym;
        int val;
        char subsym;
        int subval;
        Symbol* prv;
        Symbol* nxt;

        Symbol(char sym, int val, char subsym, int subval)
        : sym(sym), val(val),
        subsym(subsym), subval(subval),
        prv(NULL), nxt(NULL) { }
    } Symbol;

    vector<Symbol> syms;
};

int main() {
    Solution sol = Solution();
//    int num = 3;
//    int num = 4;
//    int num = 9;
//    int num = 58;
    int num = 1994;
    auto res = sol.intToRoman(num);
    cout << res << endl;
    return 0;
}
