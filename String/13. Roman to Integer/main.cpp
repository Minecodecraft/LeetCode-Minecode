//
//  main.cpp
//  13. Roman to Integer
//
//  Created by 边俊林 on 2019/7/16.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/roman-to-integer/
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
        for (int i = 0; i < syms.size(); ++i) {
            hash[syms[i].sym] = &syms[i];
        }
    }

    int romanToInt(string s) {
        int p = 0;
        int res = 0;
        while (p < s.length()) {
            if (p+1 < s.length() && hash[s[p+1]]->val > hash[s[p]]->val) {
                res += hash[s[p+1]]->val - hash[s[p]]->val;
                p += 2;
            } else {
                res += hash[s[p++]]->val;
            }
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

        Symbol(char sym, int val, char subsym, int subval) : sym(sym), val(val), subsym(subsym), subval(subval), prv(NULL), nxt(NULL) { }
    } Symbol;

    vector<Symbol> syms;
    unordered_map<char, Symbol*> hash;
};

int main() {
    Solution sol = Solution();
//    string s = "III";
//    string s = "IV";
//    string s = "IX";
//    string s = "LVIII";
    string s = "MCMXCIV";
    auto res = sol.romanToInt(s);
    cout << res << endl;
    return 0;
}
