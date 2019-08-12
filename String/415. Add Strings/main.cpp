//
//  main.cpp
//  415. Add Strings
//
//  Created by 边俊林 on 2019/8/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/add-strings/
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
    string addStrings(string num1, string num2) {
        string tmp;
        int takeover, idx, num;
        takeover = idx = 0;
        while (idx < num1.length() && idx < num2.length()) {
            num = takeover + num1[num1.length() - idx - 1] - '0' + num2[num2.length() - idx - 1] - '0';
            takeover = num / 10;
            num %= 10;
            tmp.push_back(num + '0');
            ++idx;
        }
        while (idx < num1.length()) {
            num = takeover + num1[num1.length() - idx - 1] - '0';
            takeover = num / 10;
            num %= 10;
            tmp.push_back(num + '0');
            ++idx;
        }
        while (idx < num2.length()) {
            num = takeover + num2[num2.length() - idx - 1] - '0';
            takeover = num / 10;
            num %= 10;
            tmp.push_back(num + '0');
            ++idx;
        }
        if (takeover)
            tmp.push_back(takeover + '0');
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }
};

int main() {
    Solution sol = Solution();
    string num1 = "123";
    string num2 = "4567";
    auto res = sol.addStrings(num1, num2);
    cout << res << endl;
    return 0;
}
