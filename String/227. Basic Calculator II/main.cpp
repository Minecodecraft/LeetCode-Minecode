//
//  main.cpp
//  227. Basic Calculator II
//
//  Created by 边俊林 on 2019/8/6.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/basic-calculator-ii/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
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
        stringstream ss("+" + s);
        char op;
        int num, last, ans;
        num = last = ans = 0;
        while (ss >> op >> num) {
            if (op == '+' || op == '-') {
                num = op == '+' ? num : -num;
                ans += num;
            } else {
                num = op == '*' ? last * num : last / num;
                ans = ans - last + num;
            }
            last = num;
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "3+2*2";
//    string s = " 3/2 ";
//    string s = "3+5    / 2";
//    string s = "3+5    / 2 * 2";
    string s = "0-2147483647";
//    string s = "1-1+1";
    int res = sol.calculate(s);
    cout << res << endl;
    return 0;
}
