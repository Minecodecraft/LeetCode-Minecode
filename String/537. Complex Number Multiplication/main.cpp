//
//  main.cpp
//  537. Complex Number Multiplication
//
//  Created by 边俊林 on 2019/8/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/complex-number-multiplication/
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
    string complexNumberMultiply(string a, string b) {
        int ln, rn, la, ra;
        int l, r;
        l = r = 0;

        while (a[r] != '+') ++r;
        ln = stoi(a.substr(l, r-l));
        l = ++r;
        while (a[r] != 'i') ++r;
        la = stoi(a.substr(l, r-l));

        l = r = 0;
        while (b[r] != '+') ++r;
        rn = stoi(b.substr(l, r-l));
        l = ++r;
        while (b[r] != 'i') ++r;
        ra = stoi(b.substr(l, r-l));

        int num = ln*rn - la*ra;
        int alpha = ln*ra + rn*la;

        return to_string(num) + "+" + to_string(alpha) + "i";
    }
};

int main() {
    Solution sol = Solution();
    string a = "1+1i";
    string b = "1+1i";
    auto res = sol.complexNumberMultiply(a, b);
    cout << res << endl;
    return 0;
}
