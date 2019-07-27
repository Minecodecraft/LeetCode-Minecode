//
//  main.cpp
//  67. Add Binary
//
//  Created by 边俊林 on 2019/7/27.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/add-binary/
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
    string addBinary(string a, string b) {
        int p, overflow, num;
        int la = a.length(), lb = b.length();
        p = overflow = 0;
        string res;
        while (p < la && p < lb) {
            num = a[la-p-1] - '0' + b[lb-p-1] - '0' + overflow;
            overflow = num / 2;
            num %= 2;
            res.push_back((num + '0'));
            ++p;
        }
        while (p < a.length()) {
            num = a[la-p-1] - '0' + overflow;
            overflow = num / 2;
            num %= 2;
            res.push_back((num + '0'));
            ++p;
        }
        while (p < b.length()) {
            num = b[lb-p-1] - '0' + overflow;
            overflow = num / 2;
            num %= 2;
            res.push_back((num + '0'));
            ++p;
        }
        if (overflow)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string a = "11";
//    string b = "1";
    string a = "1010";
    string b = "1011";
    auto res = sol.addBinary(a, b);
    cout << res << endl;
    return 0;
}
