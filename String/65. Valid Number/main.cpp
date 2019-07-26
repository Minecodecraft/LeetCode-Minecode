//
//  main.cpp
//  65. Valid Number
//
//  Created by 边俊林 on 2019/7/26.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/valid-number/
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
    // remove leading/trailling white space
    // [number]e[number]
    // number: +/- digits . digits
    // . must have digit suffix
    // e must have number suffix and number prefix
    bool isNumber(string s) {
        bool epre, esuf, hase;
        epre = esuf = hase = false;
        int l, r;
        l = 0, r = s.length()-1;
        while (l < s.length() && s[l] == ' ') ++l;
        while (r >= 0 && s[r] == ' ') --r;

        int firstres = isNumber(s, l, r, true);
        if (firstres == 0)
            return false;
        epre = true;

        if (l <= r && s[l] == 'e') {
            hase = true;
            ++l;
        } else
            return l > r;

        int secondres = isNumber(s, l, r, false);
        if (secondres == 0)
            return false;
        esuf = true;

        if (l == r+1) {
            if (hase) return epre && esuf;
            else return epre;
        }
        return false;
    }

private:
    // 0 unmatch
    // 1 matched
    // 2 end with dot
    int isNumber(string& s, int& p, int r, bool canHasDot) {
        bool haspre, hasdot, hassuf;
        haspre = hasdot = hassuf = false;
        if (s[p] == '+' || s[p] == '-')
            ++p;
        while (p <= r && isdigit(s[p])) {
            haspre = true;
            ++p;
        }
        if (p <= r && s[p] == '.') {
            if (p-1 < 0 || !isdigit(s[p-1]))
                haspre = p+1 <= r && isdigit(s[p+1]);
            if (!canHasDot) return 0;
            hasdot = true;
            ++p;
        }
        while (hasdot && p <= r && isdigit(s[p])) {
            hassuf = true;
            ++p;
        }
        if (!haspre)
            return 0;
        return 1;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> tests = {
        "0", " 0.1 ", "abc", "1 a", "2e10", " -90e3      ", " 1e", "e3", " 6e-1",
        " 99e2.5 ", "53.5e93", " --6 ", "-+3", "95a54e53",
        ".1", "3.", ".", ".1", "46.e3"
    };
    for (string ele : tests) {
        bool res = sol.isNumber(ele);
        cout << ele << " => " << (res ? "true" : "false") << endl;
    }
//    string s = "3.";
//    bool res = sol.isNumber(s);
//    cout << s << " => " << (res ? "true" : "false") << endl;
    return 0;
}
